#include<iomanip>
#include<iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <TMath.h>
#include "setup.h"
#include "Xsec.cc"
Xsec * xs = new Xsec();
using namespace std;
    //0. No Error, nominal case
    //1. TO DO 
    //2. Dark noise, variations 
    //3. Hit efficiency, variations within the difference data and MC
    //4. Light yield, variation of PE with angle btw data and MC.
    //5. Light yield, Birks quenching effect.
    //6: Beam related background (in fact, this mainly evaluate sand muons)
    //7: 2D reconstruction error
    //8: VetoUpstreamCriteria: nominal=0 planes, vary from 0->2 per 1 plane step
    //9: VetoEdgeCriteria: nominal=80cm, vary 70->100 per 10cm steps
    //10: FVCriteria: nominal=100cm, vary 50->100 per 10 cms steps
    //11: Vertexing, plane tolerance: nominal=2, vary 2->4 per 1 plane steps
    //12: Vertexing, transverse tolerance: nominal=15cm, vary 15cm->20cm per 2.5cm steps
    //13: Track matching, plane tolerance: nominal=4, vary 3->5 per 1 plane steps
    //14: INGRID/PM tracks angle matching: nominal=35°, vary 30°->40° per 5° steps
    //15: INGRID/PM tracks transverse position matching: nominal=8.5cm, vary 7.5cm->9.5 per 1cm steps

    //16: Xsec
    //17: Flux
    
 
int main(int argc, char **argv){

  /**************************************Get back environment variables*****************************************************/
  char * cINSTALLREPOSITORY = getenv("INSTALLREPOSITORY");
    
  int c=-1;
  bool MC=false;bool Data=false;
  bool SelectionOnly=false;// if true, only the latest part of the analysis (selection & unfolding) are applied
  while ((c = getopt(argc, argv, "mds")) != -1) {
    switch(c){
    case 'm':
      MC=true;
      break;
    case 'd':
      Data=true;
      break;
    case 's':
      SelectionOnly=true;
      break;
    }      
  }  
  char Name1[100], Name2[100];
  char Command001[300], Command002[300], Command003[300], Command004[300], Command005[300], Command006[300];
  char Command01[300], Command02[300], Command03[300], Command04[300], Command05[300], Command06[300];
  char Command1_1[300], Command1_2[300], Command1_3[300], Command1_4[300], Command1_5[300], Command1_6[600];
  char Command1[300], Command2[300], Command3[300], Command4[300], Command5[300], Command6[300], Command7[300], Command8[300], Command9[300], Command11[300], Command12[300], Command13[300],Command14[300], Command15[300], Command16[300], Command17[300], Command18[300];
  char  Command10[300], Command20[300], Command30[300];
  char Name[16];

  xs->Xsec::Initialize();

  ///////////FOR THE PREREQUISITE, SO DO NOT CLEAN FOR EACH ERROR/////////////////////
  sprintf(Command01,"");
  sprintf(Command02,"");
  sprintf(Command03,"");
  sprintf(Command04,"");
  sprintf(Command05,"");
  sprintf(Command06,"");

  if(!SelectionOnly){
    for(int ErrorType=StartError;ErrorType<=EndError;ErrorType++){
      //for(int ErrorType=2;ErrorType<=6;ErrorType++){//TEMP

    
    cout<<endl<<"Error Type="<<ErrorType<<endl;

      
    if(ErrorType==3){
      sprintf(Command01,"${INSTALLREPOSITORY}/XS/HitEfficiency -m -i 1 -f 100"); //Generate a file containing MC hit efficiency (XS/files_MCDataComparison/MC_CalibrationPM.root )
      sprintf(Command02,"${INSTALLREPOSITORY}/XS/HitEfficiency -r 14510 -t 14510 -i 0 -f 300"); //Generate a file containing Data hit efficiency (${INSTALLREPOSITORY}/XS/files_MCDataComparison/MC_CalibrationPM.root )
    }
    else if(ErrorType==4){
      sprintf(Command03,"${INSTALLREPOSITORY}/XS/CompareCalibrationsPM -m -i 1 -f 100"); //-> Generate a file containing each hit info for MC (XS/files_MCDataComparison/MC_CalibrationPM.root )
      sprintf(Command04,"${INSTALLREPOSITORY}/XS/CompareCalibrationsPM -r 14510 -t 14570 -i 0 -f 300");//-> Generate a file containing each hit info for Data (XS/files_MCDataComparison/Data_CalibrationPM.root )
      sprintf(Command05,"${INSTALLREPOSITORY}/XS/GeneratePEAngleDistributions -o ${INSTALLREPOSITORY}/XS/files/PEXAngle.root");//Read the data and MC files above and create the dependency of PE with angle.
    }
    if(ErrorType==5){
      sprintf(Command06,"#Don't forget to copy your MC two times and change the Birks Constant. The path and name of this MC can be changed in XSFileGenerator.c");
    }


   
      for(int n=0;n<NE[ErrorType];n++){
      double ErrorValue=Start[ErrorType]+n*Step[ErrorType];
     if(MC){
       
       for(int i=1;i<=NMCfiles;i++){
       //for(int i=1;i<=2000;i++){//TEMP
	 sprintf(Command1,"");
	 sprintf(Command1_1,"");
	 sprintf(Command1_2,"");
	 sprintf(Command1_3,"");
	 sprintf(Command1_4,"");
	 sprintf(Command1_5,"");
	 sprintf(Command1_6,"");
	sprintf(Command2,"");
	sprintf(Command3,"");
	sprintf(Command4,"");
	sprintf(Command5,"");
	sprintf(Command6,"");
	sprintf(Command7,"");
	sprintf(Command8,"");
	sprintf(Command9,"");
	sprintf(Command11,"");
	sprintf(Command12,"");
	
	sprintf(Command10,"");
	sprintf(Command20,"");
	sprintf(Command30,"");
	//sprintf(Command40,"");

	
	if(ErrorType==0){//Case w/o error

	  
	  //################################################Create the total input file####################################################################################
	  //Run 1
	  //NuMu
	  if(i<=500) sprintf(Command1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numu_Run1_%d.root -i ${MCINPUTSTORAGE}/run1/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 1",i,i);
	  else if(i<=1000) sprintf(Command1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numu_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add1/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 1",i,i-500);
	  else if(i<=1500) sprintf(Command1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numu_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add2/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 1",i,i-1000);
	  else sprintf(Command1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numu_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add3/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 1",i,i-1500);
	  
	  //NuMuBar
	  //To Modify
	  if(i<=500) sprintf(Command1_1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numubar_Run1_%d.root -i ${MCINPUTSTORAGE}/numubar/run1/11bfluka_nd2_numubar_ch_%d.nt -m 2 -f 2",i,i);
	  //if(i<=500) sprintf(Command1_1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numubar_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add1nubar/11bfluka_nd2_numubar_ch_%d.nt -m 2 -f 2",i,i);
	  else if(i<=1000) sprintf(Command1_1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numubar_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add1nubar/11bfluka_nd2_numubar_ch_%d.nt -m 2 -f 2",i,i-500);
	  else if(i<=1500) sprintf(Command1_1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numubar_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add2nubar/11bfluka_nd2_numubar_ch_%d.nt -m 2 -f 2",i,i-1000);
	  else if(i<=2000) sprintf(Command1_1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Numubar_Run1_%d.root -i ${MCINPUTSTORAGE}/run1add3nubar/11bfluka_nd2_numubar_ch_%d.nt -m 2 -f 2",i,i-1500);
	  
	  //NuE
	  if(i<=500) sprintf(Command1_2,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Nue_Run1_%d.root -i ${MCINPUTSTORAGE}/nuerun1/11bfluka_nd2_nue_ch_%d.nt -m 2 -f 3",i,i);
	  else if(i<=1000) sprintf(Command1_2,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Nue_Run1_%d.root -i ${MCINPUTSTORAGE}/nuerun1add1/11bfluka_nd2_nue_ch_%d.nt -m 2 -f 3",i,i-500);
	  else if(i<=1500) sprintf(Command1_2,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Nue_Run1_%d.root -i ${MCINPUTSTORAGE}/nuerun1add2/11bfluka_nd2_nue_ch_%d.nt -m 2 -f 3",i,i-1000);
	  else if(i<=2000) sprintf(Command1_2,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Nue_Run1_%d.root -i ${MCINPUTSTORAGE}/nuerun1add3/11bfluka_nd2_nue_ch_%d.nt -m 2 -f 3",i,i-1500);
	  
	  //Wall Bkg (mainly Sand Muons)
	  if(i<=1000) sprintf(Command1_3,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Wall_Run1_%d.root -i ${MCINPUTSTORAGE}/wall/11b_nd7_numu_o_%d_0.nt -m 2 -f 1",i,i);
	  else if(i<=2000) sprintf(Command1_3,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Wall_Run1_%d.root -i ${MCINPUTSTORAGE}/wallset2/11b_nd7_numu_o_%d_1.nt -m 2 -f 1",i,i-1000);

	  //Ingrid Bkg
	  //Horizontal modules
	  if(i<=500) sprintf(Command1_4,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDH_Run1_%d.root -i ${MCINPUTSTORAGE}/nd3numurun1/11bfluka_nd3_numu_fe_%d.nt -m 2 -f 1",i,i);
	  else if(i<=1000) sprintf(Command1_4,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDH_Run1_%d.root -i ${MCINPUTSTORAGE}/nd3numurun1add1/11bfluka_nd3_numu_fe_%d.nt -m 2 -f 1",i,i-500);
	  else if(i<=1500) sprintf(Command1_4,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDH_Run1_%d.root -i ${MCINPUTSTORAGE}/nd3numurun1add2/11bfluka_nd3_numu_fe_%d.nt -m 2 -f 1",i,i-1000);
	  else if(i<=2000) sprintf(Command1_4,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDH_Run1_%d.root -i ${MCINPUTSTORAGE}/nd3numurun1add3/11bfluka_nd3_numu_fe_%d.nt -m 2 -f 1",i,i-1500);

	  //Vertical modules
	  if(i<=500) sprintf(Command1_5,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDV_Run1_%d.root -i ${MCINPUTSTORAGE}/nd4numurun1/11bfluka_nd4_numu_fe_%d.nt -m 2 -f 1",i,i);
	  else if(i<=1000) sprintf(Command1_5,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDV_Run1_%d.root -i ${MCINPUTSTORAGE}/nd4numurun1add1/11bfluka_nd4_numu_fe_%d.nt -m 2 -f 1",i,i-500);
	  else if(i<=1500) sprintf(Command1_5,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDV_Run1_%d.root -i ${MCINPUTSTORAGE}/nd4numurun1add2/11bfluka_nd4_numu_fe_%d.nt -m 2 -f 1",i,i-1000);
	  else if(i<=2000) sprintf(Command1_5,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_INGRIDV_Run1_%d.root -i ${MCINPUTSTORAGE}/nd4numurun1add3/11bfluka_nd4_numu_fe_%d.nt -m 2 -f 1",i,i-1500);

	  //Merge Files Together
	  sprintf(Command1_6,"${INSTALLREPOSITORY}/XS/FinalMCOutputMaker -a ${MCOUTPUTSTORAGE}/PMMC_Numu_Run1_%d.root -b ${MCOUTPUTSTORAGE}/PMMC_Numubar_Run1_%d.root -c ${MCOUTPUTSTORAGE}/PMMC_Nue_Run1_%d.root -d ${MCOUTPUTSTORAGE}/PMMC_Wall_Run1_%d.root -e ${MCOUTPUTSTORAGE}/PMMC_INGRIDH_Run1_%d.root -f ${MCOUTPUTSTORAGE}/PMMC_INGRIDV_Run1_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d.root",i,i,i,i,i,i,i);
	  //##########################################################################################################################

	  

	  
	  //sprintf(Command1,"bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d.root -i /export/scraid2/data/bquilain/neutfile_pm/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 2",i,i);
	  sprintf(Command2,"${INSTALLREPOSITORY}/PM_Ana/app/IngAddNoisePMMC_new -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise.root",i,i);
	  sprintf(Command3,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon.root",i,i);
	  sprintf(Command4,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root",i,i);
	  sprintf(Command5,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  //NEUT 5.3.2
	  sprintf(Command6,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Plan.root -f 1 -m",i,i);
	  //NEUT 5.1.4.2
	  //sprintf(Command6,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PM_MC_Beam%d_BirksCorrectedMIP40_ReWeight_SciBar188_wNoise_KSana_woXtalk.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Old_%d_Plan.root -f 1 -m",i,i);
			    
	  //sprintf(Command6,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command7,"${T2KREWEIGHTREPOSITORY}/app/genWeightsFromINGRID_2015.exe -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_ReWeight2015.root",i,i);
	  //sprintf(Command6,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root",i,i);
	  //sprintf(Command5,"${INSTALLREPOSITORY}/XS/XS_CC0pi -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d.root -f 1 -m",i,i);
	  //sprintf(Command6,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan_BNJDistributions -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Plan_BNJ.root -f 1 -m",i,i);
	}
	else if(ErrorType==1) continue;
	else if(ErrorType==2){//Dark noise values.
	  sprintf(Command1,"${INSTALLREPOSITORY}/XS/IngAddNoisePMMC -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root -n %2.1f",i,i,ErrorType,n,ErrorValue);  
	  sprintf(Command2,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	  sprintf(Command3,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	  sprintf(Command4,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command5,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m",i,ErrorType,n,i,ErrorType,n);    
	}
	else if(ErrorType==3){//One should give in input the file name of the data/MC difference
	  //The best thing would be just to generate everything w/ an option
	  sprintf(Command3,"${INSTALLREPOSITORY}/XS/GenerateHitEfficiencyMask -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root",i,i,ErrorType,n);
	  sprintf(Command4,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	  sprintf(Command5,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	  sprintf(Command6,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command7,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m",i,ErrorType,n,i,ErrorType,n);    	
	}
	else if(ErrorType==4){//One should give in input the file name of the data/MC difference
	  //The best thing would be just to generate everything w/ an option
	  sprintf(Command1,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command2,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m -e %d -v ${INSTALLREPOSITORY}/XS/files/PEXAngle.root",i,i,ErrorType,n,ErrorType);

	}
	else if(ErrorType==5){
	  //pre-requisite if you change the MC: do 2 copies and change the Birks constant (cf memo): generate MC w/ Birks constant variation from 0.0208+-0.0023 cm/MeV
	  //ErrorValue=185;
	  	  //1. Change birks constant to minus value in src/IngridResponse.cc: 0.0208->0.0185
	  //2. Run this MC
	    //1. Change birks constant to minus value in src/IngridResponse.cc: 0.0208->0.0231
	    //2. Run this MC

	  if(n==0){
	    sprintf(Command1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/Birks_Minus/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_Systematics%d_%d.root -i ${MCINPUTSTORAGE}/run1/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 1",i,ErrorType,n,i);
	    sprintf(Command2,"${INSTALLREPOSITORY}/PM_Ana/app/IngAddNoisePMMC_new -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	    sprintf(Command3,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	    sprintf(Command4,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	    sprintf(Command5,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	    sprintf(Command6,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m",i,ErrorType,n,i,ErrorType,n);
	  }
	  if(n==1){
	    //ErrorValue=231;
	    sprintf(Command1,"${INSTALLREPOSITORY}/MC/ingmc_IngridRevReWeightFinal/Birks_Plus/bin/Linux-g++/IngMC -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_Systematics%d_%d.root -i ${MCINPUTSTORAGE}/run1/11bfluka_nd2_numu_ch_%d.nt -m 2 -f 1",i,ErrorType,n,i);
	    sprintf(Command2,"${INSTALLREPOSITORY}/PM_Ana/app/IngAddNoisePMMC_new -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	    sprintf(Command3,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	    sprintf(Command4,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	    sprintf(Command5,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	    sprintf(Command6,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m",i,ErrorType,n,i,ErrorType,n);
	  }
	}
	else if(ErrorType==6){
	  //sprintf(Command1,"${INSTALLREPOSITORY}/XS/CC0piSelection -s 1 -w %2.2f",ErrorValue);
	}
	else if(ErrorType>=7 && ErrorType<=10){
	  sprintf(Command1,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root -e %d -v %3.1f",i,i,ErrorType,n,ErrorType,ErrorValue);
	  sprintf(Command2,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon_Systematics%d_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root",i,ErrorType,n,i,ErrorType,n);
	  sprintf(Command3,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command4,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m",i,ErrorType,n,i,ErrorType,n);
	}
	else if(ErrorType>=11 && ErrorType<=15){
	  sprintf(Command1,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r 14000 -s 0 -f ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_recon.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -e %d -v %3.1f",i,i,ErrorType,n,ErrorType,ErrorValue);
	  sprintf(Command2,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command3,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Systematics%d_%d_Plan.root -f 1 -m",i,ErrorType,n,i,ErrorType,n);
	}
	else if(ErrorType==16) continue;
		  //sprintf(Command2,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_Plan_ReWeight2015.root -f 1 -m",i,i);
	  
	else if(ErrorType>=17){
	  if(n!=0 || ErrorType>17) continue;//this is a something only for XS errors. This is because all the error is contain in one file (the files contains nominal tree + Reweight vector) and so, we do not need to generate different files for different sources or for 7 different variations of it (-3,-2,-1,0,1,2,3)sigmas.
	    sprintf(Command1,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	    sprintf(Command2,"${T2KREWEIGHTREPOSITORY}/app/genWeightsFromINGRID_2015.exe -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d.root -o ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_ReWeight2015.root",i,i);
	    sprintf(Command3,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_wNoise_ana.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%d_ReWeight2015_Plan.root -f 1 -m -x ${MCOUTPUTSTORAGE}/PMMC_Run1_%d_ReWeight2015.root",i,i,i);
	}
	/*
	  sprintf(Command1,"${INSTALLREPOSITORY}/XS/CC0piSelection -s 1 -x);

	  sprintf(Command1,"${INSTALLREPOSITORY}/XS/CC0piSelection -s 1 -f);
	  for(int iflux=0;iflux<=10;iflux++){
	  sprintf(Command2,"${INSTALLREPOSITORY}/XS/UnfoldingOptimisation -d ${INSTALLREPOSITORY}/XS/files/MCSelected.txt -m ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics_Flux%d.txt -n 1",iflux);
	  }
	*/
      
	sprintf(Name1,"%s/MC/JobsSystematics/PMMC%d_Systematics%d_%d.sh",cINSTALLREPOSITORY,i,ErrorType,n);
	sprintf(Name2,"%s/MC/JobsSystematics/condorPMMC%d_Systematics%d_%d.sh",cINSTALLREPOSITORY,i,ErrorType,n);
	if(i==0) cout<<Name1<<" is created, and for other neutfiles also (number of neutfile = NMCFiles: see inc/setup.h"<<endl;
	ofstream ScriptMC(Name1);
	if(ScriptMC)
	  {
	    ScriptMC<<"#!/bin/bash +x"<<endl
	      /*		    <<Command1<<endl
		    <<Command1_1<<endl
		    <<Command1_2<<endl
		    <<Command1_3<<endl
	            <<Command1_4<<endl
		    <<Command1_5<<endl
		    <<Command1_6<<endl
		    <<Command2<<endl
		    <<Command3<<endl
		    <<Command4<<endl
		    <<Command5<<endl*/
		    <<Command6<<endl;
	    //		    <<Command7<<endl;
	  }
      
	
	sprintf(Command10,"Executable = ${INSTALLREPOSITORY}/MC/JobsSystematics/PMMC%d_Systematics%d_%d.sh",i,ErrorType,n);
	sprintf(Command20,"Output = ${INSTALLREPOSITORY}/MC/JobsSystematics/log_PMMC%d_Systematics%d_%d.txt",i,ErrorType,n);
	sprintf(Command30,"Error = ${INSTALLREPOSITORY}/MC/JobsSystematics/err_PMMC%d_Systematics%d_%d.txt",i,ErrorType,n);
	ofstream CondorMC(Name2);
	if(CondorMC){
	  CondorMC<<Command10<<endl
		<<"Universe        = vanilla"<<endl
		<<"Rank            = kflops"<<endl
		<<"Getenv          = True"<<endl
		<<"Requirements    = CpuIsBusy == FALSE && (machine != \"scbn00\" && machine != \"scbn01.hepnet.scphys.kyoto-u.ac.jp\" )"<<endl
		<<"Arguments      =  ${Process)"<<endl
		<<Command20<<endl
		<<Command30<<endl
		<<"Notification    = Never"<<endl
		<<"QUEUE 1"<<endl;
	}
	
      }
     }
      
     if(Data){
       ///////////////////////////////////////////DATA//////////////////////////////////////////////////////////////////////////
       char RunNumber[16];
  char SubRunNumber[16];
  int RunNum;
  int SubRunNum;

  ifstream List;
  for(int l=StartRunList;l<=EndRunList;l++){
    sprintf(Name,"%s/Data/%d000.txt",cINSTALLREPOSITORY,l);
    List.open(Name);
    char MIDAS[150];
    if(List.is_open()){
      while(!List.eof()){
	List>>MIDAS;
	//cout<<MIDAS<<", 20e="<<MIDAS[50]<<endl;
	sprintf(RunNumber,"%c%c%c%c%c",MIDAS[50],MIDAS[51],MIDAS[52],MIDAS[53],MIDAS[54]);
	sprintf(SubRunNumber,"%c%c%c%c",MIDAS[56],MIDAS[57],MIDAS[58],MIDAS[59]);
	RunNum=atoi(RunNumber);
	SubRunNum=atoi(SubRunNumber);
	
	if(RunNum<StartRun || RunNum>EndRun) continue;
	if(SubRunNum<StartSubRun || SubRunNum>EndSubRun) continue;
	cout<<RunNumber<<", SubRun="<<SubRunNumber<<endl;
	   
	//sprintf(Name1,"${INSTALLREPOSITORY}/MC/JobsSystematics/PMData_%d_%d.sh",RunNum,SubRunNum);
	//sprintf(Name2,"${INSTALLREPOSITORY}/MC/JobsSystematics/condorPMData%d_%d.sh",RunNum,SubRunNum);

	sprintf(Command1,"");
	sprintf(Command1_1,"");
	sprintf(Command1_2,"");
	sprintf(Command1_3,"");
	sprintf(Command1_4,"");
	sprintf(Command1_5,"");
	sprintf(Command1_6,"");
	sprintf(Command2,"");
	sprintf(Command3,"");
	sprintf(Command4,"");
	sprintf(Command5,"");
	sprintf(Command6,"");
	sprintf(Command7,"");
	sprintf(Command8,"");
	sprintf(Command9,"");
	sprintf(Command11,"");
	sprintf(Command12,"");
	sprintf(Command13,"");
	sprintf(Command14,"");
	sprintf(Command15,"");
	sprintf(Command16,"");
	sprintf(Command17,"");
	sprintf(Command18,"");
	
	sprintf(Command10,"");
	sprintf(Command20,"");
	sprintf(Command30,"");
	//sprintf(Command40,"");

	if(ErrorType==0){
	  sprintf(Command1,"${INGRIDSOFTWARE_INGRID}/v1r1/Linux-x86_64/Calc_MPPC_new_ci_2.exe -r %d -s %d -t 1",RunNum,SubRunNum);
	  sprintf(Command2,"if [ -f ${DATAOUTPUTSTORAGE_CALIB}/ingrid_%08d_%04d_Calib00.root ]",RunNum,SubRunNum);
	  sprintf(Command3,"then");
	  sprintf(Command4,"${INGRIDSOFTWARE_INGRID}/v1r1/Linux-x86_64/DSTMaker.exe -r %d -s %d -t 1",RunNum,SubRunNum);
	  sprintf(Command5,"${INGRIDSOFTWARE_INGRID}/v1r1/Linux-x86_64/IngCalib_ADCNLCorrected.exe -r %d -s %d -f ${DATAOUTPUTSTORAGE_DST}/ingrid_%08d_%04d.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_calib.root",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum);
	  sprintf(Command6,"${INGRIDSOFTWARE_INGRID}/v1r1/Linux-x86_64/DSTMaker.exe -r %d -s %d -t 1 -p",RunNum,SubRunNum);
	  sprintf(Command7,"${INGRIDSOFTWARE_INGRID}/v1r1/Linux-x86_64/IngCalib_ADCNLCorrected.exe -r %d -s %d -f ${DATAOUTPUTSTORAGE_ROOT}/ingrid_%08d_%04d.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmcalib.root -p",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum);
	  sprintf(Command8,"${INSTALLREPOSITORY}/Reconstruction/app/IngMergePM -r %d -s %d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmcalib.root -a ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_calib.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmerged.root",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum);
	  ////////////////////////////////////////////////////////RECONSTRUCTION////////////////////////////////////////////////////////////
	  sprintf(Command9,"if [ -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmerged.root ]",RunNum,SubRunNum);
	  sprintf(Command11,"then");
	  sprintf(Command12,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r %d -s %d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmerged.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSrecon_woXTalk.root",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum);
	  //////////////////////////////////////////////////////PM ANALYSIS////////////////////////////////////////////////////////////
	  sprintf(Command13,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r %d -s %d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSrecon_woXTalk.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPMana_woXTalk.root",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum);
	  sprintf(Command14,"${INGRIDSOFTWARE_INGRIDFORMAT}/app/IngAddBSD -r %08d -s %04d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPMana_woXTalk.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPManabsd_woXTalk.root -v -p",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum);
	  sprintf(Command15,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command16,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPManabsd_woXTalk.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_%08d_%04d.root -f 1 -n 5",RunNum,SubRunNum,RunNum,SubRunNum);
	  sprintf(Command17,"fi");
	  sprintf(Command18,"fi");
	}
	else if(ErrorType>=7 && ErrorType<=10){
	  sprintf(Command1,"${INSTALLREPOSITORY}/Reconstruction/app/PMreconRevOfficial -r %d -s %d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmerged.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSrecon_woXTalk_Systematics%d_%d.root -e %d -v %3.1f",RunNum,SubRunNum,RunNum,SubRunNum,RunNum,SubRunNum,ErrorType,n,ErrorType,ErrorValue);
	  sprintf(Command2,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r %d -s %d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSrecon_woXTalk_Systematics%d_%d.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPMana_woXTalk_Systematics%d_%d.root",RunNum,SubRunNum,RunNum,SubRunNum,ErrorType,n,RunNum,SubRunNum,ErrorType,n);
	  sprintf(Command3,"${INGRIDSOFTWARE_INGRIDFORMAT}/app/IngAddBSD -r %08d -s %04d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPMana_woXTalk_Systematics%d_%d.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPManabsd_woXTalk_Systematics%d_%d.root -v -p",RunNum,SubRunNum,RunNum,SubRunNum,ErrorType,n,RunNum,SubRunNum,ErrorType,n);
	  sprintf(Command4,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command5,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPManabsd_woXTalk_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_%08d_%04d_Systematics%d_%d.root -f 1 -n 5",RunNum,SubRunNum,ErrorType,n,RunNum,SubRunNum,ErrorType,n);
	}
	else if(ErrorType>=11 && ErrorType<=15){
	  sprintf(Command1,"${INSTALLREPOSITORY}/Reconstruction/app/PMAnaRevOfficial -r %d -s %d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSrecon_woXTalk_Systematics%d_%d.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPMana_woXTalk_Systematics%d_%d.root",RunNum,SubRunNum,RunNum,SubRunNum,ErrorType,n,RunNum,SubRunNum,ErrorType,n);
	  sprintf(Command2,"${INGRIDSOFTWARE_INGRIDFORMAT}/app/IngAddBSD -r %08d -s %04d -f ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPMana_woXTalk_Systematics%d_%d.root -o ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPManabsd_woXTalk_Systematics%d_%d.root -v -p",RunNum,SubRunNum,RunNum,SubRunNum,ErrorType,n,RunNum,SubRunNum,ErrorType,n);
	  sprintf(Command3,"source ${INSTALLREPOSITORY}/source_T2KReweight.sh");
	  sprintf(Command4,"${INSTALLREPOSITORY}/XS/XS_CC0pi_Plan -i ${DATAOUTPUTSTORAGE_RECONSTRUCTED}/ingrid_%08d_%04d_pmmergedKSPManabsd_woXTalk_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/root_input/XSFormat_%08d_%04d_Systematics%d_%d.root -f 1 -n 5",RunNum,SubRunNum,ErrorType,n,RunNum,SubRunNum,ErrorType,n);
	}
	else continue;
	sprintf(Name1,"%s/MC/JobsSystematics/PMData_Run%d_SubRun%d_Systematics%d_%d.sh",cINSTALLREPOSITORY,RunNum,SubRunNum,ErrorType,n);
	sprintf(Name2,"%s/MC/JobsSystematics/condorPMData_Run%d_SubRun%d_Systematics%d_%d.sh",cINSTALLREPOSITORY,RunNum,SubRunNum,ErrorType,n);
	cout<<"Name="<<Name1<<endl;
	ofstream ScriptData(Name1);
	if(ScriptData)
	  {
	    ScriptData<<"#!/bin/bash +x"<<endl
	      //  <<Command1<<endl
		  <<Command2<<endl
		  <<Command3<<endl
	      //  <<Command4<<endl
	      //  <<Command5<<endl
	      //  <<Command6<<endl
	      //  <<Command7<<endl
	      //  <<Command8<<endl
		  <<Command9<<endl
		  <<Command11<<endl
		  <<Command12<<endl
		  <<Command13<<endl
		  <<Command14<<endl
		  <<Command15<<endl
		  <<Command16<<endl
		  <<Command17<<endl
	    <<Command18<<endl;
	  }
	
	
	sprintf(Command10,"Executable = ${INSTALLREPOSITORY}/MC/JobsSystematics/PMData_Run%d_SubRun%d_Systematics%d_%d.sh",RunNum,SubRunNum,ErrorType,n);
	sprintf(Command20,"Output = ${INSTALLREPOSITORY}/MC/JobsSystematics/log_PMData_Run%d_SubRun%d_Systematics%d_%d.txt",RunNum,SubRunNum,ErrorType,n);
	sprintf(Command30,"Error = ${INSTALLREPOSITORY}/MC/JobsSystematics/err_PMData_Run%d_SubRun%d_Systematics%d_%d.txt",RunNum,SubRunNum,ErrorType,n);
	ofstream CondorData(Name2);
	if(CondorData){
	  CondorData<<Command10<<endl
		<<"Universe        = vanilla"<<endl
		<<"Rank            = kflops"<<endl
		<<"Getenv          = True"<<endl
		<<"Requirements    = CpuIsBusy == FALSE && (machine != \"scbn00\" && machine != \"scbn01.hepnet.scphys.kyoto-u.ac.jp\" )"<<endl
		<<"Arguments      =  ${Process)"<<endl
		<<Command20<<endl
		<<Command30<<endl
		<<"Notification    = Never"<<endl
		<<"QUEUE 1"<<endl;
	}	
      }
    }
    List.close();
  }
  //cout<<endl;
     }
    }
  }
  }  


  ///////////////////////////////////PREREQUISITE//////////////////////////////////////////
  sprintf(Name1,"%s/MC/JobsSystematics/Prerequisite.sh",cINSTALLREPOSITORY);
  sprintf(Name2,"%s/MC/JobsSystematics/condorPrerequisite.sh",cINSTALLREPOSITORY);
  //sprintf(Name1,"$(INSTALLREPOSITORY)/MC/JobsSystematics/Prerequisite.sh");
  //sprintf(Name2,"$(INSTALLREPOSITORY)/MC/JobsSystematics/condorPrerequisite.sh");
  //sprintf(Name1,"/export/scraid3/data/bquilain/CC0pi_XS/MC/JobsSystematics/Prerequisite.sh");
  //sprintf(Name2,"/export/scraid3/data/bquilain/CC0pi_XS/MC/JobsSystematics/condorPrerequisite.sh");
  cout<<"Name="<<Name1<<endl;
  ofstream Script(Name1);
  if(Script)
    {
      Script<<"#!/bin/bash +x"<<endl
	    <<Command01<<endl
	    <<Command02<<endl
	    <<Command03<<endl
	    <<Command04<<endl;
    }
  
  
  sprintf(Command10,"Executable = ${INSTALLREPOSITORY}/MC/JobsSystematics/Prerequisite.sh");
  sprintf(Command20,"Output = ${INSTALLREPOSITORY}/MC/JobsSystematics/log_Prerequisite.txt");
  sprintf(Command30,"Error = ${INSTALLREPOSITORY}/MC/JobsSystematics/err_Prerequisite.txt");
  ofstream CondorPre(Name2);
  if(CondorPre){
    CondorPre<<Command10<<endl
	  <<"Universe        = vanilla"<<endl
	  <<"Rank            = kflops"<<endl
	  <<"Getenv          = True"<<endl
	  <<"Requirements    = CpuIsBusy == FALSE && (machine != \"scbn00\" && machine != \"scbn01.hepnet.scphys.kyoto-u.ac.jp\" )"<<endl
	  <<"Arguments      =  ${Process)"<<endl
	  <<Command20<<endl
	  <<Command30<<endl
	  <<"Notification    = Never"<<endl
	  <<"QUEUE 1"<<endl;
  }



  
  //////////////////////////////////////POSTREQUISITE////////////////////////////////////////////////. Ne prends pas en compte les Xsec pour l'instant
  for(int ErrorType=StartError;ErrorType<=EndError;ErrorType++){
    for(int n=0;n<NE[ErrorType];n++){
      double ErrorValue=Start[ErrorType]+n*Step[ErrorType];
      ///////////FOR THE POSTREQUISITE, SO SHOULD CLEAN FOR EACH ERROR/////////////////////
      sprintf(Command001,"");
      sprintf(Command002,"");
      sprintf(Command003,"");
      sprintf(Command004,"");
      sprintf(Command005,"");
      sprintf(Command006,"");

      sprintf(Name1,"%s/MC/JobsSystematics/Postrequisite_Systematics%d_%d.sh",cINSTALLREPOSITORY,ErrorType,n);
      sprintf(Name2,"%s/MC/JobsSystematics/condorPostrequisite_Systematics%d_%d.sh",cINSTALLREPOSITORY,ErrorType,n);
      cout<<"Name="<<Name1<<endl;
      ofstream ScriptPost(Name1);
      if(ErrorType==0){
	sprintf(Command001,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%s_Plan.root -o ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -s 1 -e %d -v %3.3f -m -p %2.2f","%d",ErrorType,n,ErrorType,ErrorValue,DataPOT);
	sprintf(Command002,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_%s_%s.root -o ${INSTALLREPOSITORY}/XS/files/DataSelected_Systematics%d_%d -s 1 -e %d -v %3.3f","%08d","%04d",ErrorType,n,ErrorType,ErrorValue);
	sprintf(Command004,"${INSTALLREPOSITORY}/XS/UnfoldingOptimisation_Dvt -d ${INSTALLREPOSITORY}/XS/files/DataSelected_Systematics%d_%d -m ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -o ${INSTALLREPOSITORY}/XS/files/DataUnfolded_Systematics%d_%d -n 1",ErrorType,n,ErrorType,n,ErrorType,n);
      }
      else if(ErrorType==6) sprintf(Command001,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%s_Plan.root -o ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -s 1 -e %d -v %3.3f -m -w %2.2f -p %2.2f","%d",ErrorType,n,ErrorType,ErrorValue,ErrorValue,DataPOT);
      else sprintf(Command001,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%s_Systematics%d_%d_Plan.root -o ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -s 1 -e %d -v %3.3f -m -p %2.2f","%d",ErrorType,n,ErrorType,n,ErrorType,ErrorValue,DataPOT);
      if(ErrorType>=7 && ErrorType<=15){
	sprintf(Command002,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_%s_%s_Systematics%d_%d.root -o ${INSTALLREPOSITORY}/XS/files/DataSelected_Systematics%d_%d -s 1 -e %d -v %3.3f","%08d","%04d",ErrorType,n,ErrorType,n,ErrorType,ErrorValue);
	sprintf(Command004,"${INSTALLREPOSITORY}/XS/UnfoldingOptimisation_Dvt -d ${INSTALLREPOSITORY}/XS/files/DataSelected_Systematics%d_%d -m ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -o ${INSTALLREPOSITORY}/XS/files/DataUnfolded_Systematics%d_%d -n 1",ErrorType,n,ErrorType,n,ErrorType,n);
      }
      else if(ErrorType==16){
	sprintf(Command001,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%s_Plan.root -o ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -s 1 -e %d -v %3.3f -m -p %2.2f","%d",ErrorType,n,ErrorType,ErrorValue,DataPOT);	
      }
      else if(ErrorType>=17){
	//double XsecVariation=ErrorValue-CenterXsecVariations*(ErrorType-Systematics_Xsec_Start);//The variation of Xsec parameter, in #sigma. A number between 0 and 175 - the center of the current systematic source (nominal). For example, for Xsec error source #10, it starts from 7*(10-1)=63 and ends at 70. from 63 to 70, it contains the variariation of -3,-2,-1,0,1,2,3 sigma respectively. The center is then located at 66. For the example of a 2 sigma variation, the substraction will be therefore equal to: 68-66=2, which gives the number of sigmas!        
	sprintf(Command001,"${INSTALLREPOSITORY}/XS/CC0piSelection -i ${INSTALLREPOSITORY}/XS/root_input/XSFormat_Run1_%s_ReWeight2015_Plan.root -o ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -s 1 -e %d -v %3.3f -m -p %2.2f","%d",ErrorType,n,ErrorType,ErrorValue,DataPOT);
      }
      sprintf(Command003,"${INSTALLREPOSITORY}/XS/UnfoldingOptimisation_Dvt -d ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -m ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics%d_%d -o ${INSTALLREPOSITORY}/XS/files/MCUnfolded_Systematics%d_%d -n 1",ErrorType,n,ErrorType,n,ErrorType,n);// Not for stat. variations, since unfolded is already done differently
      if(ErrorType==1) sprintf(Command003,"${INSTALLREPOSITORY}/XS/UnfoldingOptimisation_Dvt -d ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics0_0 -m ${INSTALLREPOSITORY}/XS/files/MCSelected_Systematics0_0 -o ${INSTALLREPOSITORY}/XS/files/MCUnfolded_Systematics%d_%d -n 1 -s 1",ErrorType,n);

      
      if(ScriptPost)
	{
	  ScriptPost<<"#!/bin/bash +x"<<endl
		    <<Command001<<endl
		    <<Command002<<endl
		    <<Command003<<endl
		    <<Command004<<endl;
	}
      
      sprintf(Command10,"Executable = ${INSTALLREPOSITORY}/MC/JobsSystematics/Postrequisite_Systematics%d_%d.sh",ErrorType,n);
      sprintf(Command20,"Output = ${INSTALLREPOSITORY}/MC/JobsSystematics/log_Postrequisite_Systematics%d_%d.txt",ErrorType,n);
      sprintf(Command30,"Error = ${INSTALLREPOSITORY}/MC/JobsSystematics/err_Postrequisite_Systematics%d_%d.txt",ErrorType,n);
      ofstream CondorPost(Name2);
      if(CondorPost){
	CondorPost<<Command10<<endl
	      <<"Universe        = vanilla"<<endl
	      <<"Rank            = kflops"<<endl
	      <<"Getenv          = True"<<endl
	      <<"Requirements    = CpuIsBusy == FALSE && (machine != \"scbn00\" && machine != \"scbn01.hepnet.scphys.kyoto-u.ac.jp\" )"<<endl
	      <<"Arguments      =  ${Process)"<<endl
	      <<Command20<<endl
	      <<Command30<<endl
	      <<"Notification    = Never"<<endl
	      <<"QUEUE 1"<<endl;
      }
    }
  }



  
}