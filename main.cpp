#include "InteractionProfiler.h"
#include <QtWidgets/QApplication>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "http.h"
#include <sys/stat.h>
#include <boost/filesystem.hpp>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

string exec(const char* cmd) {
	char buffer[128];
	string result = "";
	shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) throw runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer, 128, pipe.get()) != NULL)
			result += buffer;
	}
	return result;
}

void printToFile(const string& fname, const string& toprint) {
	ofstream output;

	try {
		// NOTE: passing fname.c_str() not just fname
		output.open(fname.c_str(), ios::app);
	}
	catch (exception e) {
		cout << "err occurred: " << e.what() << endl;
	}

	output << toprint;
	output.close();
}

unordered_map<string, vector<float>> interactions_from_pdb (const string& name, const string& dirpath) {
	string cmd = "printinteractions.exe " + dirpath + "\\" + name + ".pdb";
	vector<string> result = split(exec(cmd.c_str()), '\n');
	unordered_map<string, vector<float>> interactions;

	// Build key/value map from output using interaction type/interaction distance array
	for (const string& line : result) {
		vector<string> splitLine = split(line, '=');
		if (splitLine.size() > 0) {
			string label = split(splitLine[0], ':')[2];
			vector<float> valueFloats = {};
			if (splitLine.size() > 1) {
				vector<string> valueStrings = split(splitLine[1], ',');
				for (const string& value : valueStrings) {
					valueFloats.push_back(stof(value));
				}
			}
			interactions[label] = valueFloats;
		}
	}
	return interactions;
}

struct Protein {
	string name;
	float ic50;
	unordered_map<string, vector<float>> interactions;
};

bool fileExists(const string& filename) {
	struct stat buf;
	return (stat(filename.c_str(), &buf) != -1);
}

int main(int argc, char *argv[])
{
	qDebug("Test msg");
	vector<Protein> proteins;
	string pdbPath = "PDB_Files";
	vector<string> pdbNames = { "1tqf", "4hhb" };

	boost::filesystem::create_directory(pdbPath.c_str());
	for (const string& name : pdbNames) {
		Protein protein;
		protein.name = name;
		string file = (pdbPath + "\\" + name + ".pdb");
		utility::string_t path = utility::conversions::to_string_t("/download/" + name + ".pdb");
		if (!fileExists(file)) {
			http_request(utility::conversions::to_string_t(file), U("https://files.rcsb.org"), path);
		}
		protein.interactions = interactions_from_pdb(name, pdbPath);
		proteins.push_back(protein);
	}

  QApplication a(argc, argv);
  InteractionProfiler w;
  w.show();
  return a.exec();
}
