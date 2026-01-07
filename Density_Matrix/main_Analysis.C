#include <iostream>
#include <fstream>
#include <string>
#include "ntp_Lambda_Analyzer.h"
#include "ntp_Lambda_Calculator.h"
#include "ntp_Lambda_Histogram.h"
#include "ntp_Lambda_Reader.h"
void main_Analysis(){
	std::vector<std::string> FullInputFiles;
	std::string OutputFile="Density_Matrix.root";
	/*
	std::ifstream filelist("Inputfilelist.txt");
	if (!filelist.is_open()) {
		std::cerr <<"can't open the file" <<std::endl;
	}
	std::string directory="/star/u/jjiastar/pwg/Spin/production/output/";
	std::string line;
	while (std::getline(filelist,line)){
		FullInputFiles.push_back(directory+line);

	}
	*/
	std::vector<std::string> SameEventInputFiles;
	FullInputFiles.push_back("25130036_0.root.picoLambdaAnaMaker.root");
	SameEventInputFiles.push_back("25130036_0.root.picoLambdaAnaMaker.root");

	ntp_Lambda_Reader *mySameEventReader  = new ntp_Lambda_Reader(SameEventInputFiles);
	ntp_Lambda_Reader *myMixEventReader   = new ntp_Lambda_Reader(FullInputFiles);

	ntp_Lambda_Calculator *myCalculator   = new ntp_Lambda_Calculator();
	ntp_Lambda_Histogram *myHistogram     = new ntp_Lambda_Histogram(mySameEventReader,myCalculator,OutputFile);

	myHistogram->InitHitogram();

    ntp_Lambda_Analyzer *myAnalyzer       = new ntp_Lambda_Analyzer(mySameEventReader, myMixEventReader, myCalculator, myHistogram );

    myAnalyzer->Analysis_SameEvent();
    //myAnalyzer->Analysis_MixEvent();
	myHistogram->WriteAll();


}
