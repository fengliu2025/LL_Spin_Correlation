#include "ntp_Lambda.C"


void Convert(){
	ntp_Lambda myClass;
	for(int i=0;i<1;i++){
		myClass.InPutFileList().push_back( Form("")  );
		myClass.OutPutFileList().push_back(Form("")  );
	}

	myClass.Loop();

}