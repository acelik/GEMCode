globalX_globalY()

// Warning...
// if you want to plot odd chambers, comment out the macro which is written for even chambers, want to plot even chambers then command out the macro written for odd chambers. In the following, it has been speicified where macro both even chambers and odd chambers starts from and ends.By default macro for even chambers has been commented out


//Macro for odd chambers in Region -1 starts here


{

// This section sets basic plotting preferences
  gROOT->ForceStyle();
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptTitle(kFALSE); // Takes default title off of plots
  gStyle->SetOptStat(0); // Takes statistics box off of plots
  gStyle->SetMarkerStyle(20);
// creates canvas
  TCanvas* c1 = new TCanvas("c1","c1",600,600);
  hist = new TH1F("hist","",1000000,-10000,10000);

  TFile *_file0 = TFile::Open("gem_sh_ana_100k.root"); //put path of the root file
  _file0->cd("GEMSimHitAnalyzer");

  double XposGEM [36];
  double YposGEM [36];
  double XposCSC [36];
  double YposCSC [36];

    
// For CSC and GEM chambers, wanted information is read from the root file and graph constructed in the colors indicated below
  
    GEMSimHits->Draw("globalY:globalX","region==-1&&chamber%2==1&&chamber<=36"); //if you want to plot region 1 then change "region==-1 into region==1"
  h=(TGraph*)gPad->FindObject("Graph");
  TGraph* GEMglobalzx= h->Clone();
  GEMglobalzx->SetMarkerColor(kRed);
  GEMglobalzx->SetMarkerSize(0.1);

  CSCSimHits->Draw("globalY:globalX","endcap==2&&chamber%2==1&&ring==1&&chamber<=36"); //if you want to plot CSC's in region 1 then change "endcap==2 into endcap=1"
  h=(TGraph*)gPad->FindObject("Graph");
  TGraph* CSCglobalzx= h->Clone();
  CSCglobalzx->SetMarkerColor(kBlue);
  CSCglobalzx->SetMarkerSize(0.1);
    

    // For every single odd CSC and GEM chambers, mean X and mean Y value are calculated and kept in strings and those values printed in the screen
  
    for (int n=1; n<37; n+=2)
  {
    cout << n << ", ";
    GEMSimHits->Draw("globalY:globalX",TString::Format("chamber==%i",n));
    h=(TGraph*)gPad->FindObject("Graph");
    TGraph* TEMPglobalzx= h->Clone();
    cout<<"For GEM chamber: "<<n<<endl;
    cout<<"Your x average is: "<<TEMPglobalzx->GetMean(1)<<" And your y average is: "<<TEMPglobalzx->GetMean(2)<<endl;
    XposGEM[n-1]=TEMPglobalzx->GetMean(1); //this is for odd chambers
    YposGEM[n-1]=TEMPglobalzx->GetMean(2); // this is for odd chambers
      
  

    CSCSimHits->Draw("globalY:globalX",TString::Format("chamber==%i",n));
    h=(TGraph*)gPad->FindObject("Graph");
    TGraph* TEMP2globalzx= h->Clone();
    cout<<"For CSC chamber: "<<n<<endl;
    cout<<"Your x average is: "<<TEMP2globalzx->GetMean(1)<<" And your y average is: "<<TEMP2globalzx->GetMean(2)<<endl;
    XposCSC[n-1]=TEMP2globalzx->GetMean(1);
    YposCSC[n-1]=TEMP2globalzx->GetMean(2);
  

  }

    // Name of the axis and ranges defined here
  hist->GetXaxis()->SetTitle("Global x [cm]");
  hist->GetYaxis()->SetTitle("Global y [cm]");
    
  hist->GetYaxis()->SetTitleOffset(1.3);
  hist->SetAxisRange(-350,350,"X");
  hist->SetAxisRange(-350,350,"Y");
  hist->Draw("axis");

    //for each CSC and GEM odd chambers, numbering is written in the plot automatically, numbers' color and positions adjusted
  for (int n=1; n<37; n+=2)
  {
   TText *NumberingGEM = new TText(1.7*XposGEM[n-1],1.7*YposGEM[n-1],TString::Format("%i",n));
   NumberingGEM->SetTextSize(0.025);
    NumberingGEM->SetTextAngle(0);
    NumberingGEM->SetTextColor(kRed);
    NumberingGEM->DrawClone("same");
      TText *NumberingCSC = new TText(1.05*XposCSC[n-1],1.05*YposCSC[n-1],TString::Format("%i",n));
    NumberingCSC->SetTextSize(0.025);
    NumberingCSC->SetTextAngle(0);
    NumberingCSC->SetTextColor(kBlue);
    NumberingCSC->DrawClone("same");
  }
  
  // CSC and GEM drawn in the same canvas
    
    CSCglobalzx->Draw("same p");
    
    GEMglobalzx->Draw("same p");
    
  // Captions and their position and colors etc.

  TText *tt_CSC = new TText(295,326,"CSC");
  tt_CSC->SetTextSize(0.03);
  tt_CSC->SetTextAngle(0);
  tt_CSC->SetTextColor(kBlue);
  tt_CSC->Draw("same");

  TText *tt_GEM = new TText(295,305,"GEM");
  tt_GEM->SetTextSize(0.03);
  tt_GEM->SetTextAngle(0);
  tt_GEM->SetTextColor(kRed);
  tt_GEM->Draw("same");

  TText *tt_TEXT = new TText(-330,326,"Odd Chambers in Region -1"); // if you are plotting chambers in region 1 then replaced the caption "Region -1 with Region 1"
  tt_TEXT->SetTextSize(0.03);
  tt_TEXT->Draw("same");

  c1->SaveAs("globalxy_odd_rm1.pdf");


}


//Macro for odd chambers in region -1 ends here.





//Macro for even chambers in region -1 starts here.

/*

{
    
    // This section sets basic plotting preferences
    gROOT->ForceStyle();
    gROOT->SetStyle("Plain");
    gStyle->SetPalette(1);
    gStyle->SetOptTitle(kFALSE); // Takes default title off of plots
    gStyle->SetOptStat(0); // Takes statistics box off of plots
    gStyle->SetMarkerStyle(20);
    
    TCanvas* c1 = new TCanvas("c1","c1",600,600);
    hist = new TH1F("hist","",1000000,-10000,10000);
    
    TFile *_file0 = TFile::Open("gem_sh_ana_100k.root"); //put path of root file
    _file0->cd("GEMSimHitAnalyzer");
    
    double XposGEM [36];
    double YposGEM [36];
    double XposCSC [36];
    double YposCSC [36];
    
    //
    
    GEMSimHits->Draw("globalY:globalX","region==-1&&chamber%2==0&&chamber<=36"); //if you want to plot region 1 then change "region==-1 into region==1"
    h=(TGraph*)gPad->FindObject("Graph");
    TGraph* GEMglobalzx= h->Clone();
    GEMglobalzx->SetMarkerColor(kRed);
    GEMglobalzx->SetMarkerSize(0.1);
    
    CSCSimHits->Draw("globalY:globalX","endcap==2&&chamber%2==0&&ring==1&&chamber<=36"); //if you want to plot CSC's in region 1 then change "endcap==2 into endcap=1"
    h=(TGraph*)gPad->FindObject("Graph");
    TGraph* CSCglobalzx= h->Clone();
    CSCglobalzx->SetMarkerColor(kBlue);
    CSCglobalzx->SetMarkerSize(0.1);
    
    for (int n=2; n<37; n+=2)
    {
        cout << n << ", ";
        GEMSimHits->Draw("globalY:globalX",TString::Format("chamber==%i",n));
        h=(TGraph*)gPad->FindObject("Graph");
        TGraph* TEMPglobalzx= h->Clone();
        cout<<"For GEM chamber: "<<n<<endl;
        cout<<"Your x average is: "<<TEMPglobalzx->GetMean(1)<<" And your y average is: "<<TEMPglobalzx->GetMean(2)<<endl;
       
        
        XposGEM[n-2]=TEMPglobalzx->GetMean(1); //this is for even chambers
        YposGEM[n-2]=TEMPglobalzx->GetMean(2); //this is for even chambers
        
        CSCSimHits->Draw("globalY:globalX",TString::Format("chamber==%i",n));
        h=(TGraph*)gPad->FindObject("Graph");
        TGraph* TEMP2globalzx= h->Clone();
        cout<<"For CSC chamber: "<<n<<endl;
        cout<<"Your x average is: "<<TEMP2globalzx->GetMean(1)<<" And your y average is: "<<TEMP2globalzx->GetMean(2)<<endl;
        
        XposCSC[n-2]=TEMP2globalzx->GetMean(1);
        YposCSC[n-2]=TEMP2globalzx->GetMean(2);
        
    }
    
    hist->GetXaxis()->SetTitle("Global x [cm]");
    hist->GetYaxis()->SetTitle("Global y [cm]");
    
    hist->GetYaxis()->SetTitleOffset(1.3);
    hist->SetAxisRange(-350,350,"X");
    hist->SetAxisRange(-350,350,"Y");
    hist->Draw("axis");
    
    for (int n=2; n<37; n+=2)
    {
        TText *NumberingGEM = new TText(1.7*XposGEM[n-2],1.7*YposGEM[n-2],TString::Format("%i",n));
        NumberingGEM->SetTextSize(0.025);
        NumberingGEM->SetTextAngle(0);
        NumberingGEM->SetTextColor(kRed);
        NumberingGEM->DrawClone("same");
        TText *NumberingCSC = new TText(1.05*XposCSC[n-2],1.05*YposCSC[n-2],TString::Format("%i",n));
        NumberingCSC->SetTextSize(0.025);
        NumberingCSC->SetTextAngle(0);
        NumberingCSC->SetTextColor(kBlue);
        NumberingCSC->DrawClone("same");
    }
    CSCglobalzx->Draw("same p");
    
    GEMglobalzx->Draw("same p");
    
    //caption
    
    TText *tt_CSC = new TText(295,326,"CSC");
    tt_CSC->SetTextSize(0.03);
    tt_CSC->SetTextAngle(0);
    tt_CSC->SetTextColor(kBlue);
    tt_CSC->Draw("same");
    
    TText *tt_GEM = new TText(295,305,"GEM");
    tt_GEM->SetTextSize(0.03);
    tt_GEM->SetTextAngle(0);
    tt_GEM->SetTextColor(kRed);
    tt_GEM->Draw("same");
    
    TText *tt_TEXT = new TText(-330,326,"Odd Chambers in Region -1"); // if you are plotting chambers in region 1 then replaced the caption "Region -1 with Region 1"
    tt_TEXT->SetTextSize(0.03);
    tt_TEXT->Draw("same");
    
   
    c1->SaveAs("globalxy_even_rm1.pdf");
    
}
}




//Macro for even chambers in region -1 ends here.
*/


