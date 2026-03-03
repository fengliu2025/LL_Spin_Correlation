

class new_Tree{
public:

   TTree* 		  tree;	

   Int_t           eventId;
   Float_t         Vz;
   //Int_t           mNTrigs;
   //Int_t           mTrigId[3];   //[mNTrigs]
   //Int_t           mNTrks;
   //Float_t         high_pt[6];   //[mNTrks]
   //Float_t         high_phi[6];   //[mNTrks]
   //Float_t         high_eta[6];   //[mNTrks]
   Int_t           NLambda;
   Int_t           p1_InEventID[5];   //[NLambda]
   Float_t         p1_pt[5];   //[NLambda]
   Float_t         p1_phi[5];   //[NLambda]
   Float_t         p1_eta[5];   //[NLambda]
   Float_t         p1_dca[5];   //[NLambda]
   Int_t           p1_ch[5];   //[NLambda]
   Int_t           p1_hasTOFinfo[5];   //[NLambda]
  
   Int_t           p2_InEventID[5];   //[NLambda]
   Float_t         p2_pt[5];   //[NLambda]
   Float_t         p2_phi[5];   //[NLambda]
   Float_t         p2_eta[5];   //[NLambda]
   Float_t         p2_dca[5];   //[NLambda]
   Int_t           p2_hasTOFinfo[5];   //[NLambda]
  
   Int_t           pair_charge[5];   //[NLambda]
   Float_t         pair_DCAdaughters[5];   //[NLambda]
   Float_t         pair_theta[5];   //[NLambda]
   Float_t         pair_decayL[5];   //[NLambda]
   Float_t         pair_phi[5];   //[NLambda]
   Float_t         pair_eta[5];   //[NLambda]
   Float_t         pair_pt[5];   //[NLambda]
   Float_t         pair_mass[5];   //[NLambda]

   new_Tree();
   void MakeNewTree();
   void ResetTree();
   void Fill();
   void WriteTree(std::string OutPutFile);
   
};

new_Tree::new_Tree(){

}

void new_Tree::MakeNewTree(){
	tree = new TTRee("ntp_Lambda","ntp_Lambda");


	ntp_Lambda->Branch("eventId", &eventId, "eventId/I");       //Int_t eventId
    ntp_Lambda->Branch("Vz", &Vz, "Vz/F"); //VzVzVPDmax
    
    /*
    ntp_Lambda->Branch("high_pt", high_pt, "high_pt[mNTrks]/F");  
    ntp_Lambda->Branch("high_phi", high_phi, "high_phi[mNTrks]/F");
    ntp_Lambda->Branch("high_eta", high_eta, "high_eta[mNTrks]/F");
	*/
    /*
    ntp_Lambda->Branch("lead_pt", &lead_pt, "lead_pt/F");               //Float_t p1_pt
    ntp_Lambda->Branch("lead_phi", &lead_phi, "lead_phi/F");             //Float_t p1_phi
    ntp_Lambda->Branch("lead_eta", &lead_eta, "lead_eta/F");             //Float_t p1_eta
    
    ntp_Lambda->Branch("sublead_pt", &sublead_pt, "sublead_pt/F");               //Float_t p1_pt
    ntp_Lambda->Branch("sublead_phi", &sublead_phi, "sublead_phi/F");             //Float_t p1_phi
    ntp_Lambda->Branch("sublead_eta", &sublead_eta, "sublead_eta/F");             //Float_t p1_eta
    */
    ntp_Lambda->Branch("NLambda", &NLambda, "NLambda/I");
    
    //proton
    ntp_Lambda->Branch("p1_InEventID", p1_InEventID, "p1_InEventID[NLambda]/I");               //Float_t p1_InEventID
    ntp_Lambda->Branch("p1_pt", p1_pt, "p1_pt[NLambda]/F");               //Float_t p1_pt
    ntp_Lambda->Branch("p1_phi", p1_phi, "p1_phi[NLambda]/F");             //Float_t p1_phi
    ntp_Lambda->Branch("p1_eta", p1_eta, "p1_eta[NLambda]/F");             //Float_t p1_eta
    ntp_Lambda->Branch("p1_dca", p1_dca, "p1_dca[NLambda]/F");               //Float_t p1_dca
    ntp_Lambda->Branch("p1_ch", p1_ch, "p1_ch[NLambda]/I");               //Float_t p1_ch
    ntp_Lambda->Branch("p1_hasTOFinfo", p1_hasTOFinfo, "p1_hasTOFinfo[NLambda]/I");   //Float_t p1_hasTOFinfo
    //ntp_Lambda->Branch("p1_dedx", p1_dedx, "p1_dedx[NLambda]/F");
    //ntp_Lambda->Branch("p1_beta", p1_beta, "p1_beta[NLambda]/F");

    //pion
    ntp_Lambda->Branch("p2_InEventID", p2_InEventID, "p2_InEventID[NLambda]/I");               //Float_t p2_InEventID
    ntp_Lambda->Branch("p2_pt", p2_pt, "p2_pt[NLambda]/F");               //Float_t p2_pt
    ntp_Lambda->Branch("p2_phi", p2_phi, "p2_phi[NLambda]/F");             //Float_t p2_phi
    ntp_Lambda->Branch("p2_eta", p2_eta, "p2_eta[NLambda]/F");             //Float_t p2_eta
    ntp_Lambda->Branch("p2_dca", p2_dca, "p2_dca[NLambda]/F");               //Float_t p2_dca
    //ntp_Lambda->Branch("p2_ch", p2_ch, "p2_ch[NLambda]/I");               //Float_t p2_ch
    ntp_Lambda->Branch("p2_hasTOFinfo", p2_hasTOFinfo, "p2_hasTOFinfo[NLambda]/I");   //Float_t p2_hasTOFinfo
    //ntp_Lambda->Branch("p2_dedx", p2_dedx, "p2_dedx[NLambda]/F");
    //ntp_Lambda->Branch("p2_beta", p2_beta, "p2_beta[NLambda]/F");

    //pair
    ntp_Lambda->Branch("pair_charge", pair_charge, "pair_charge[NLambda]/I");      //Int_t charge
    ntp_Lambda->Branch("pair_DCAdaughters", pair_DCAdaughters, "pair_DCAdaughters[NLambda]/F");      //Int_t pair_DCAdaughters
    ntp_Lambda->Branch("pair_theta", pair_theta, "pair_theta[NLambda]/F");   //Float_t pair_theta
    //ntp_Lambda->Branch("pair_cosThetaStar", pair_cosThetaStar, "pair_cosThetaStar[NLambda]/F");   //Float_t pair_cosThetaStar
    ntp_Lambda->Branch("pair_decayL", pair_decayL, "pair_decayL[NLambda]/F");  //Float_t pair_decayL
    ntp_Lambda->Branch("pair_phi", pair_phi, "pair_phi[NLambda]/F");      //Float_t pair_phi
    ntp_Lambda->Branch("pair_eta", pair_eta, "pair_eta[NLambda]/F");      //Float_t pair_eta
    ntp_Lambda->Branch("pair_pt", pair_pt, "pair_pt[NLambda]/F");        //Float_t pair_pt
    ntp_Lambda->Branch("pair_mass", pair_mass, "pair_mass[NLambda]/F");    //Float_t pair_mass
	//...
}

void new_Tree::ResetTree(){
	tree->Reset();
}

void new_Tree::Fill(){
	tree->Fill();
}	



void new_Tree::WriteTree(std::string OutPutFile){
	TFile *fout=TFile::Open(OutPutFile.c_str() , "RECREATE");
	tree->Write();
	fout->Close();
	delete fout;


}

