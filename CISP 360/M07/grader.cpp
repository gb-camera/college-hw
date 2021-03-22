// -----------------------------------------------------------------------
// grader.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

// -----------------------------------------------------------------------
// global constants
const string INFILE_PREFIX = "rawgrades-";
const string OUTFILE_PREFIX = "grade-report-";
const string IN_FILE_EXT = ".csv";
const string OUT_FILE_EXT = ".txt";

const size_t LEN_PREFIX = INFILE_PREFIX.length();
const size_t LEN_F_EXT = 3;

///this will be used for extra space between fields in the output file
const string SPACER = "  ";

const double A_GRADE = 90.0;
const double B_GRADE = 80.0;
const double C_GRADE = 70.0;
const double D_GRADE = 60.0;
// anything below D_GRADE is an 'F'

// output field widths
const int FW_NAME = 24;
const int FW_SCORE = 4;
const int FW_LOW = 3;
const int FW_TOTAL = 5;
const int FW_AVG = 7;
const int FW_GRADE = 3;
const int FW_SCORE_X4 = FW_SCORE * 4;

// -----------------------------------------------------------------------
// function prototypes

// top-level functions
string getInputFilename();
string deriveOutputFilename(const string &inFname);
bool openFiles(const string &inName, const string &outName, ifstream &fin, ofstream &fout);
void processGradeFile(ifstream &fin, ofstream &fout);

// helper functions
// TODO (0): declare function prototypes for the helper functions
bool validInputFilename(const string &fname);
void parseStudentRecord(const string &line, string &name, string &id, int &s1, int &s2, int &s3, int &s4);
int min(int a, int b);
int min(int a, int b, int c, int d);
char gradeFromScore(double score);
void processLine(ostream &out, const string &line);
void writeReportHeader(ofstream &out);

// -----------------------------------------------------------------------
// program entry point
int main() {
    // main() has been implemented for you; no need to change anything here
    ifstream fin;
    ofstream fout;

    string inFilename = getInputFilename();
    string outFilename = deriveOutputFilename(inFilename);

    if (!openFiles(inFilename, outFilename, fin, fout)) {
        return EXIT_FAILURE;
    }

    cout << "Processing " << inFilename << " ..." << endl;
    processGradeFile(fin, fout);
    cout << "Report written to " << outFilename << endl;

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------
// helper function definitions

// Returns true if `fname` of the form "rawgrades-<className>.csv"
bool validInputFilename(const string &fname) {
    int nameLen = fname.length();

    // TODO (1): implement validation on the given filename
       ///look for the presence of INFILE_PREFIX
       ///look for the presence of IN_FILE_EXT
       ///ensure the name length is MORE than just the prefix and extension
    if(nameLen > 14) {
        if(fname.find(INFILE_PREFIX) == string::npos || fname.find(IN_FILE_EXT) == string::npos) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
// Parses a record, placing the substrings into `name`, `id`, and `s1...s4`
void parseStudentRecord(const string &line,
                        string &name, string &id, int &s1, int &s2, int &s3, int &s4) {

    // TODO (2): carve up the input line into substrings
    //           placing the results into the appropriate reference variables
    int comma1 = line.find(',');
    int comma2 = line.find(',', comma1 + 1);
    int comma3 = line.find(',', comma2 + 1);
    int comma4 = line.find(',', comma3 + 1);
    int comma5 = line.find(',', comma4 + 1);

    string s1str = line.substr(comma2 + 1, comma3 - comma2 - 1);
    string s2str = line.substr(comma3 + 1, comma4 - comma3 - 1);
    string s3str = line.substr(comma4 + 1, comma5 - comma4 - 1);
    string s4str = line.substr(comma5 + 1);

    name = line.substr(0, comma1);
    id = line.substr(comma1 + 1, comma2 - comma1 - 1);
    s1 = atoi(s1str.c_str());
    s2 = atoi(s2str.c_str());
    s3 = atoi(s3str.c_str());
    s4 = atoi(s4str.c_str());
}

// Returns the smaller of the two values
int min(int a, int b) {
    // TODO (3): return minimum value
    if(a > b) {
        return b;
    }
    else {
        return a;
    }
}

// Returns the smallest of all the values
int min(int a, int b, int c, int d) {
    // TODO (4): return minimum value
    // HINT: use min(int, int)
    if(min(a, b) > min(c, d)) {
        return min(c, d);
    }
    else {
        return min(a, b);
    }
    return 0;
}

// Returns a letter grade for the given score
char gradeFromScore(double score) {
    char grade = 'F';

    // TODO (5): adjust grade based on score
    if(score >= A_GRADE) {
        grade = 'A';
    }
    else if(score >= B_GRADE && score < A_GRADE) {
        grade = 'B';
    }
    else if(score >= C_GRADE && score < B_GRADE) {
        grade = 'C';
    }
    else if(score >= D_GRADE && score < C_GRADE) {
        grade = 'D';
    }
    return grade;
}

// Processes a line read from the raw-grades input file
void processLine(ostream &out, const string &line) {
    string studentName, studentId, scores;
    int score1, score2, score3, score4;
    int total, lowest;
    double average;
    char letterGrade;

    // TODO (6): process the raw record...
    parseStudentRecord(line, studentName, studentId, score1, score2, score3, score4);
    // - compute total (but subtract the lowest score)
    lowest = min(score1, score2, score3, score4);
    total = score1 + score2 + score3 + score4 - lowest;
    // - compute the average (of 3 scores)
    average = total / 3.0;
    letterGrade = gradeFromScore(average);

    // TODO (7): write the formatted record to the report file
    out << left << setw(FW_NAME) << setfill(' ') << studentName;
    out << SPACER;
    out << right << setw(FW_SCORE) << setfill(' ') << score1;
    out << right << setw(FW_SCORE) << setfill(' ') << score2;
    out << right << setw(FW_SCORE) << setfill(' ') << score3;
    out << right << setw(FW_SCORE) << setfill(' ') << score4;
    out << SPACER;
    out << "(";
    out << setw(FW_LOW) << setfill(' ') << right << lowest;
    out << ")";
    out << SPACER;
    out << setw(FW_TOTAL) << setfill(' ') << right << total;
    out << SPACER;
    out << setw(FW_AVG) << setfill(' ') << fixed << setprecision(2) << right << average;
    out << SPACER;
    out << "  " << letterGrade;
    out << endl;
}

// Writes the report header to the given output stream
void writeReportHeader(ofstream &out) {
    // Lucky you! I've implemented this one for you. Don't change it! :)
    out << left;

    out << setw(FW_NAME) << "Name" << SPACER
        << setw(FW_SCORE_X4) << "Scores" << SPACER
        << "(" << setw(FW_LOW) << "Low" << ")" << SPACER
        << setw(FW_TOTAL) << "Total" << SPACER
        << setw(FW_AVG) << "Average" << SPACER
        << "Grade"
        << endl;

    out << setfill('-');

    out << setw(FW_NAME) << "" << SPACER
        << setw(FW_SCORE_X4) << "" << SPACER
        << "-" << setw(FW_LOW) << "" << "-" << SPACER
        << setw(FW_TOTAL) << "" << SPACER
        << setw(FW_AVG) << "" << SPACER
        << "-----"
        << endl;

    out << setfill(' ') << fixed << setprecision(2);
}


// -----------------------------------------------------------------------
// top-level function definitions

// Returns a validated input filename from the user
string getInputFilename() {
    string fname;

    // TODO (8): Repeatedly prompt the user for a filename
    //            until it matches the required form.
    cout << "Enter input filename (rawgrades-<id>.csv): " << endl;
    cin  >> fname;
    while(!validInputFilename(fname)) {
        cout << endl << "Enter input filename (rawgrades-<id>.csv): ";
        cin  >> fname;
    }
    return fname;
}

// Derives the output filename from the given input filename
string deriveOutputFilename(const string &inFname) {

    // TODO (9): Generate the output file name
       ///grade-report-<className>.txt
       ///use .replace to replace the prefix and the extension
    string outName = inFname;
    outName.replace(0, 10, OUTFILE_PREFIX);
    outName.replace(outName.find('.'), 4, OUT_FILE_EXT);
    return outName;
}

// Returns true only if both files opened without error
bool openFiles(const string &inName, const string &outName, ifstream &fin, ofstream &fout) {

    // TODO (10): open input and output files, associate with the given streams
    // HINT:
    //   open input;  if fails, write message and return false
    //   open output; if fails, write message and return false
    //   return true
    fin.open(inName);
    if(!fin.is_open()) {
        cout << "Failed to open for read: " << inName;
        return false;
    }
    fout.open(outName);
    if(!fout.is_open()) {
        cout << "Failed to open for write: " << outName;
        return false;
    }
    return true; 
}

// Read input records, process, write formatted output records
void processGradeFile(ifstream &fin, ofstream &fout) {
    // This function, too, has been implemented for you... nothing to do here
    string rawLine;

    writeReportHeader(fout);
    while (getline(fin, rawLine)) {
        processLine(fout, rawLine);
    }
}

// -----------------------------------------------------------------------
