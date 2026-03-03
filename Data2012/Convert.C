#include "ntp_Lambda.C"


void Convert(){
	ntp_Lambda myClass;
	for(int i=0;i<1;i++){
                myClass.InPutFileList().push_back( Form("output_1.root")  );
                myClass.OutPutFileList().push_back(Form("/gpfs01/star/scratch/fengliu/LL_Spin_2012/Output0.root")  );
     }

	myClass.Loop();

}