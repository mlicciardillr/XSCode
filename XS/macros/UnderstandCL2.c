{
  //The first parameter is a normalisation coefficient.
  //the second parameter is the most probable value.
  //the third parameter correspond to Lambda in most book
  TFile * f0 = new TFile("/home/bquilain/CC0pi_XS/XS/root_input/XSFormat_Sand_Run1_1_Plan_RandomPE.root");
  
  TF1 * PDF = (TF1*) f0->Get("f_PMSci_Plan");
  TF1 * Cumulative = (TF1*) f0->Get("CL_PMSci_Plan");

  TCanvas * c0 = new TCanvas();
  PDF->Draw();
  Cumulative->Draw("same");
  
  TRandom3 * r = new TRandom3();
  TH1D * CL_Uniform = new TH1D("CL_Uniform","",100,0.,1.);
  TH1D * CL_PDF = new TH1D("CL_PDF","",100,0.,1.);
  TH1D * CL_PDF2 = new TH1D("CL_PDF2","",100,0.,1.);

  int NPoints=100000;
  for(int i=0;i<NPoints;i++){
    double X=r->Uniform(0,300);
    CL_Uniform->Fill(Cumulative->Eval(X));

    double X0=PDF->GetRandom();//Estimate the #pe
    CL_PDF->Fill(Cumulative->Eval(X0));

    double X1=PDF->GetRandom()*1.3;//Estimate the #pe
    CL_PDF2->Fill(Cumulative->Eval(X1));

  }
  TCanvas * c2 = new TCanvas();
  CL_Uniform->SetLineColor(1);
  CL_Uniform->SetLineWidth(2);
  CL_Uniform->Draw();
  CL_PDF->SetLineColor(2);
  CL_PDF->SetLineWidth(2);
  CL_PDF->Draw("same");
  CL_PDF2->SetLineColor(4);
  CL_PDF2->SetLineWidth(2);
  CL_PDF2->Draw("same");

}
