/**************************************************************************************
 *
 *	File Name :	plot_bbsep_real.h
 *	Description : to plot leptonic top distribution under different matching type
 *	Making Date : 191018~
 *
 *	Author : Chen-Yu Chuang
 *	using : {exe's name} {rootfile's name} {new pdf's name}
 *
 ****************************************************************************************/

#ifndef PLOT_BBSEP_REAL_NO_H
#define PLOT_BBSEP_REAL_NO_H


#include <string>
#include <iostream>
#include "string.h"

using namespace std;

void plot_bbsep_real_no(string file_name, string pdf_name)
{
	

	pdf_name = pdf_name + "_real_no.pdf";

	TH1F* h_correct_t;
	TH1F* h_charge_mis_t;
	TH1F* h_mistag_t;

	TH1F* h_correct_mu;
	TH1F* h_charge_mis_mu;
	TH1F* h_mistag_mu;
	
	TH1F* h_correct_el;
	TH1F* h_charge_mis_el;
	TH1F* h_mistag_el;

	TH2D* h_mvamax_mass_t;

	file_name = "rootFile/" + file_name;
    

	TFile* f = new TFile(file_name.c_str());		//if we execute it in the directory TopCPViolation
	f->GetObject("h_correct_t",h_correct_t);	
	f->GetObject("h_charge_mis_t",h_charge_mis_t);
	f->GetObject("h_mistag_t",h_mistag_t);

	f->GetObject("h_correct_mu",h_correct_mu);
	f->GetObject("h_correct_el",h_correct_el);
	f->GetObject("h_charge_mis_mu",h_charge_mis_mu);
	f->GetObject("h_charge_mis_el",h_charge_mis_el);
	f->GetObject("h_mistag_mu",h_mistag_mu);
	f->GetObject("h_mistag_el",h_mistag_el);

	f->GetObject("h_mvamax_mass_t",h_mvamax_mass_t);

/*	//normalize
	double no_cor_t = h_correct_t->Integral();
	double no_cm_t = h_charge_mis_t->Integral();
	double no_mt_t = h_mistag_t->Integral();

	double no_cor_mu = h_correct_mu->Integral();
	double no_cm_mu = h_charge_mis_mu->Integral();
	double no_mt_mu = h_mistag_mu->Integral();

	double no_cor_el = h_correct_el->Integral();
	double no_cm_el = h_charge_mis_el->Integral();
	double no_mt_el = h_mistag_el->Integral();

	h_correct_t->Scale( 1./no_cor_t );
	h_charge_mis_t->Scale( 1./no_cm_t );
	h_mistag_t->Scale( 1./no_mt_t );

	h_correct_mu->Scale( 1./no_cor_mu );
	h_charge_mis_mu->Scale( 1./no_cm_mu );
	h_mistag_mu->Scale( 1./no_mt_mu );

	h_correct_el->Scale( 1./no_cor_el );
	h_charge_mis_el->Scale( 1./no_cm_el );
	h_mistag_el->Scale( 1./no_mt_el );
*/

	TCanvas* c = new TCanvas("c");
	//c->SetLogy(true);

	h_correct_t->SetStats( false );
	h_charge_mis_t->SetStats( false );
	h_mistag_t->SetStats( false );

	h_correct_mu->SetStats( false );
	h_charge_mis_mu->SetStats( false );
	h_mistag_mu->SetStats( false );
	h_correct_el->SetStats( false );
	h_charge_mis_el->SetStats( false );
	h_mistag_el->SetStats( false );

	h_mvamax_mass_t->SetStats(false);

	
	h_correct_t->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_t->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_t->SetFillColorAlpha(kRed,0.1);

	h_correct_mu->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_mu->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_mu->SetFillColorAlpha(kRed,0.1);
	h_correct_el->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_el->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_el->SetFillColorAlpha(kRed,0.1);


	h_correct_t->SetFillStyle(4050);
	h_charge_mis_t->SetFillStyle(4050);
	h_mistag_t->SetFillStyle(4050);

	h_correct_mu->SetFillStyle(4050);
	h_charge_mis_mu->SetFillStyle(4050);
	h_mistag_mu->SetFillStyle(4050);
	h_correct_el->SetFillStyle(4050);
	h_charge_mis_el->SetFillStyle(4050);
	h_mistag_el->SetFillStyle(4050);


	h_correct_t->SetLineColor(kBlue);
	h_charge_mis_t->SetLineColor(kGreen+1);
	h_mistag_t->SetLineColor(kRed);

	h_correct_mu->SetLineColor(kBlue);
	h_charge_mis_mu->SetLineColor(kGreen+1);
	h_mistag_mu->SetLineColor(kRed);
	h_correct_el->SetLineColor(kBlue);
	h_charge_mis_el->SetLineColor(kGreen+1);
	h_mistag_el->SetLineColor(kRed);


	h_correct_t->SetLineWidth(2);
	h_charge_mis_t->SetLineWidth(2);
	h_mistag_t->SetLineWidth(2);

	h_correct_mu->SetLineWidth(2);
	h_charge_mis_mu->SetLineWidth(2);
	h_mistag_mu->SetLineWidth(2);
	h_correct_el->SetLineWidth(2);
	h_charge_mis_el->SetLineWidth(2);
	h_mistag_el->SetLineWidth(2);

	/*
	h_correct->Draw("HIST");
	c->Print("chi2_value_tt.pdf(","Title:Correct Matching case");
	h_charge_mis->Draw("HIST");
	c->Print("chi2_value_tt.pdf","Title:Charge Misidentified case");
	h_mistag->Draw("HIST");
	c->Print("chi2_value_tt.pdf","Title:Mistag case");
	*/
	double l_x_m = 0.29;
    double l_x_M = 0.95-0.34;
    double l_y_m = 0.68;
    double l_y_M = 0.6/0.7-0.05;

	if(file_name.find("MLP")!=string::npos ||file_name.find("BDTG")!=string::npos)
	{
		l_x_m = 0.29;
    	l_x_M = 0.95-0.34;
    	l_y_m = 0.68;
    	l_y_M = 0.6/0.7-0.05;
	}
	else if(file_name.find("BDT")!=string::npos)
	{
		l_x_m = 0.95-0.24;
    	l_x_M = 0.89;
    	l_y_m = 0.68;
    	l_y_M = 0.6/0.7-0.05;
	}

	auto legend1 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend1->SetTextFont( 43 );
	legend1->SetTextSize( 13 );
	legend1->SetBorderSize( 0 );

	legend1->AddEntry( (TObject*)0, "Muon Channel" , "" );	
	legend1->AddEntry( h_correct_mu , "Correct Matching" );
	legend1->AddEntry( h_charge_mis_mu , "b#bar{b} Misidentified" );
	legend1->AddEntry( h_mistag_mu , "Mistag" );

	auto legend2 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend2->SetTextFont( 43 );
	legend2->SetTextSize( 13 );
	legend2->SetBorderSize( 0 );
	
	legend2->AddEntry( (TObject*)0, "Electron Channel" , "" );	
	legend2->AddEntry( h_correct_el , "Correct Matching" );
	legend2->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend2->AddEntry( h_mistag_el , "Mistag" );
    
    auto legend3 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend3->SetTextFont( 43 );
	legend3->SetTextSize( 13 );
	legend3->SetBorderSize( 0 );
	
	legend3->AddEntry( (TObject*)0, "" , "" );	
	legend3->AddEntry( h_correct_el , "Correct Matching" );
	legend3->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend3->AddEntry( h_mistag_el , "Mistag" );
	
	h_correct_mu->GetYaxis()->SetTitleOffset(1.5);
	h_correct_mu->Draw("HIST");
	h_charge_mis_mu->Draw("HIST SAME");
	h_mistag_mu->Draw("HIST SAME");
	legend1->Draw("SAME");
	string name1 = pdf_name + "(";
	c->Print(name1.c_str(),"Title:Muon Channel");

	h_correct_el->GetYaxis()->SetTitleOffset(1.5);
	h_correct_el->Draw("HIST");
	h_charge_mis_el->Draw("HIST SAME");
	h_mistag_el->Draw("HIST SAME");
	legend2->Draw("SAME");
    string name2 = pdf_name;
	c->Print(name2.c_str(),"Title:Electron Channel");

	h_correct_t->GetYaxis()->SetTitleOffset(1.5);
	h_correct_t->GetYaxis()->SetTitle( "events" );
	h_correct_t->GetXaxis()->SetTitle( "max mva value" );
    
    h_correct_t->Draw("HIST");
	h_charge_mis_t->Draw("HIST SAME");
	h_mistag_t->Draw("HIST SAME");
    legend3->Draw("SAME");
    string name3 = pdf_name;
    c->Print(name3.c_str(),"Title:Total");


    c->SetLogy(false);

    h_mvamax_mass_t->GetYaxis()->SetTitle("max mva value");
	h_mvamax_mass_t->GetXaxis()->SetTitle("M_{jjb}(Invariant Mass)");
	h_mvamax_mass_t->GetZaxis()->SetTitle("events No.");
	h_mvamax_mass_t->GetZaxis()->SetLabelSize(0.02);
	h_mvamax_mass_t->GetZaxis()->SetTitleOffset(1.2);
	h_mvamax_mass_t->GetYaxis()->SetTitleOffset(1.2);

    gStyle->SetPalette(kBird);
    h_mvamax_mass_t->Draw("COLZ");
    string name4 = pdf_name + ")";
	c->Print(name4.c_str(),"Title:MVA value - jjb Mass");   
    


	//Save these 4 hist to be a root file
	
	//*****make space free*****//
	
	//delete h_correct_mu;
	//delete h_charge_mis_mu;
	//delete h_mistag_mu;

	//delete h_chi2_data_mu;	

	//delete h_correct_el;
	//delete h_charge_mis_el;
	//delete h_mistag_el;

	//delete h_chi2_data_el;	
	
	delete c;

}

void plot_bbsep_mva(string file_name, string pdf_name)
{
	
	pdf_name = pdf_name + "_ratio.pdf";

	TH1F* h_correct_t;
	TH1F* h_charge_mis_t;
	TH1F* h_mistag_t;

	TH1F* h_correct_mu;
	TH1F* h_charge_mis_mu;
	TH1F* h_mistag_mu;
	
	TH1F* h_correct_el;
	TH1F* h_charge_mis_el;
	TH1F* h_mistag_el;

	TH2D* h_mvamax_mass_t;

	file_name = "rootFile/" + file_name;
    

	TFile* f = new TFile(file_name.c_str());		//if we execute it in the directory TopCPViolation
	f->GetObject("h_correct_t",h_correct_t);	
	f->GetObject("h_charge_mis_t",h_charge_mis_t);
	f->GetObject("h_mistag_t",h_mistag_t);

	f->GetObject("h_correct_mu",h_correct_mu);
	f->GetObject("h_correct_el",h_correct_el);
	f->GetObject("h_charge_mis_mu",h_charge_mis_mu);
	f->GetObject("h_charge_mis_el",h_charge_mis_el);
	f->GetObject("h_mistag_mu",h_mistag_mu);
	f->GetObject("h_mistag_el",h_mistag_el);

	f->GetObject("h_mvamax_mass_t",h_mvamax_mass_t);

//normalize
	double no_cor_t = h_correct_t->Integral(0,h_correct_t->GetNbinsX()+1);
	double no_cm_t = h_charge_mis_t->Integral(0,h_charge_mis_t->GetNbinsX()+1);
	double no_mt_t = h_mistag_t->Integral(0,h_mistag_t->GetNbinsX()+1);

	double no_cor_mu = h_correct_mu->Integral(0,h_correct_mu->GetNbinsX()+1);
	double no_cm_mu = h_charge_mis_mu->Integral(0,h_charge_mis_mu->GetNbinsX()+1);
	double no_mt_mu = h_mistag_mu->Integral(0,h_mistag_mu->GetNbinsX()+1);

	double no_cor_el = h_correct_el->Integral(0,h_correct_el->GetNbinsX()+1);
	double no_cm_el = h_charge_mis_el->Integral(0,h_charge_mis_el->GetNbinsX()+1);
	double no_mt_el = h_mistag_el->Integral(0,h_mistag_el->GetNbinsX()+1);

	h_correct_t->Scale( 1./no_cor_t );
	h_charge_mis_t->Scale( 1./no_cm_t );
	h_mistag_t->Scale( 1./no_mt_t );

	h_correct_mu->Scale( 1./no_cor_mu );
	h_charge_mis_mu->Scale( 1./no_cm_mu );
	h_mistag_mu->Scale( 1./no_mt_mu );

	h_correct_el->Scale( 1./no_cor_el );
	h_charge_mis_el->Scale( 1./no_cm_el );
	h_mistag_el->Scale( 1./no_mt_el );


	TCanvas* c = new TCanvas("c");
	c->SetLogy(true);

	h_correct_t->SetStats( false );
	h_charge_mis_t->SetStats( false );
	h_mistag_t->SetStats( false );

	h_correct_mu->SetStats( false );
	h_charge_mis_mu->SetStats( false );
	h_mistag_mu->SetStats( false );
	h_correct_el->SetStats( false );
	h_charge_mis_el->SetStats( false );
	h_mistag_el->SetStats( false );

	h_mvamax_mass_t->SetStats(false);

	
	h_correct_t->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_t->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_t->SetFillColorAlpha(kRed,0.1);

	h_correct_mu->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_mu->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_mu->SetFillColorAlpha(kRed,0.1);
	h_correct_el->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_el->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_el->SetFillColorAlpha(kRed,0.1);


	h_correct_t->SetFillStyle(4050);
	h_charge_mis_t->SetFillStyle(4050);
	h_mistag_t->SetFillStyle(4050);

	h_correct_mu->SetFillStyle(4050);
	h_charge_mis_mu->SetFillStyle(4050);
	h_mistag_mu->SetFillStyle(4050);
	h_correct_el->SetFillStyle(4050);
	h_charge_mis_el->SetFillStyle(4050);
	h_mistag_el->SetFillStyle(4050);


	h_correct_t->SetLineColor(kBlue);
	h_charge_mis_t->SetLineColor(kGreen+1);
	h_mistag_t->SetLineColor(kRed);

	h_correct_mu->SetLineColor(kBlue);
	h_charge_mis_mu->SetLineColor(kGreen+1);
	h_mistag_mu->SetLineColor(kRed);
	h_correct_el->SetLineColor(kBlue);
	h_charge_mis_el->SetLineColor(kGreen+1);
	h_mistag_el->SetLineColor(kRed);


	h_correct_t->SetLineWidth(2);
	h_charge_mis_t->SetLineWidth(2);
	h_mistag_t->SetLineWidth(2);

	h_correct_mu->SetLineWidth(2);
	h_charge_mis_mu->SetLineWidth(2);
	h_mistag_mu->SetLineWidth(2);
	h_correct_el->SetLineWidth(2);
	h_charge_mis_el->SetLineWidth(2);
	h_mistag_el->SetLineWidth(2);

	/*
	h_correct->Draw("HIST");
	c->Print("chi2_value_tt.pdf(","Title:Correct Matching case");
	h_charge_mis->Draw("HIST");
	c->Print("chi2_value_tt.pdf","Title:Charge Misidentified case");
	h_mistag->Draw("HIST");
	c->Print("chi2_value_tt.pdf","Title:Mistag case");
	*/
	double l_x_m = 0.29;
    double l_x_M = 0.95-0.34;
    double l_y_m = 0.68;
    double l_y_M = 0.6/0.7-0.05;

	if(file_name.find("MLP")!=string::npos ||file_name.find("BDTG")!=string::npos)
	{
		l_x_m = 0.29;
    	l_x_M = 0.95-0.34;
    	l_y_m = 0.68;
    	l_y_M = 0.6/0.7-0.05;
	}
	else if(file_name.find("BDT")!=string::npos)
	{
		l_x_m = 0.95-0.26;
    	l_x_M = 0.89;
    	l_y_m = 0.68;
    	l_y_M = 0.6/0.7-0.05;
	}

	auto legend1 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend1->SetTextFont( 43 );
	legend1->SetTextSize( 13 );
	legend1->SetBorderSize( 0 );

	legend1->AddEntry( (TObject*)0, "Muon Channel" , "" );	
	legend1->AddEntry( h_correct_mu , "Correct Matching" );
	legend1->AddEntry( h_charge_mis_mu , "b#bar{b} Misidentified" );
	legend1->AddEntry( h_mistag_mu , "Mistag" );

	auto legend2 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend2->SetTextFont( 43 );
	legend2->SetTextSize( 13 );
	legend2->SetBorderSize( 0 );
	
	legend2->AddEntry( (TObject*)0, "Electron Channel" , "" );	
	legend2->AddEntry( h_correct_el , "Correct Matching" );
	legend2->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend2->AddEntry( h_mistag_el , "Mistag" );
    
    auto legend3 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend3->SetTextFont( 43 );
	legend3->SetTextSize( 13 );
	legend3->SetBorderSize( 0 );
	
	legend3->AddEntry( (TObject*)0, "" , "" );	
	legend3->AddEntry( h_correct_el , "Correct Matching" );
	legend3->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend3->AddEntry( h_mistag_el , "Mistag" );


	h_correct_mu->SetMaximum( h_correct_mu->GetMaximum() * 10 );
	h_correct_el->SetMaximum( h_correct_el->GetMaximum() * 10 );
	h_correct_t->SetMaximum( h_correct_t->GetMaximum() * 10 );
	
	h_correct_mu->GetYaxis()->SetTitleOffset(1.5);
	h_correct_mu->GetYaxis()->SetTitle( "Ratio" );
	h_correct_mu->GetXaxis()->SetTitle( "max MVA score" );
	h_correct_mu->Draw("HIST");
	h_charge_mis_mu->Draw("HIST SAME");
	h_mistag_mu->Draw("HIST SAME");
	legend1->Draw("SAME");
	string name1 = pdf_name + "(";
	c->Print(name1.c_str(),"Title:Muon Channel");

	h_correct_el->GetYaxis()->SetTitleOffset(1.5);
	h_correct_el->GetYaxis()->SetTitle( "Ratio" );
	h_correct_el->GetXaxis()->SetTitle( "max MVA score" );
	h_correct_el->Draw("HIST");
	h_charge_mis_el->Draw("HIST SAME");
	h_mistag_el->Draw("HIST SAME");
	legend2->Draw("SAME");
    string name2 = pdf_name;
	c->Print(name2.c_str(),"Title:Electron Channel");

	h_correct_t->GetYaxis()->SetTitleOffset(1.5);
	h_correct_t->GetYaxis()->SetTitle( "Ratio" );
	h_correct_t->GetXaxis()->SetTitle( "max MVA score" );
    
    h_correct_t->Draw("HIST");
	h_charge_mis_t->Draw("HIST SAME");
	h_mistag_t->Draw("HIST SAME");
    legend3->Draw("SAME");
    string name3 = pdf_name;
    c->Print(name3.c_str(),"Title:Total");


    c->SetLogy(false);

    h_mvamax_mass_t->GetYaxis()->SetTitle("max MVA score");
	h_mvamax_mass_t->GetXaxis()->SetTitle("M_{jjb}(Invariant Mass)");
	h_mvamax_mass_t->GetZaxis()->SetTitle("events No.");
	h_mvamax_mass_t->GetZaxis()->SetLabelSize(0.02);
	h_mvamax_mass_t->GetZaxis()->SetTitleOffset(1.2);
	h_mvamax_mass_t->GetYaxis()->SetTitleOffset(1.2);

    gStyle->SetPalette(kBird);
    h_mvamax_mass_t->Draw("COLZ");
    string name4 = pdf_name + ")";
	c->Print(name4.c_str(),"Title:MVA value - jjb Mass");   
    


	//Save these 4 hist to be a root file
	
	//*****make space free*****//
	
	//delete h_correct_mu;
	//delete h_charge_mis_mu;
	//delete h_mistag_mu;

	//delete h_chi2_data_mu;	

	//delete h_correct_el;
	//delete h_charge_mis_el;
	//delete h_mistag_el;

	//delete h_chi2_data_el;	
	
	delete c;

}

void plot_bbsep_chi2(string file_name, string pdf_name)
{
	

	pdf_name = pdf_name + "_real_no.pdf";

	TH1F* h_correct_t;
	TH1F* h_charge_mis_t;
	TH1F* h_mistag_t;

	TH1F* h_correct_mu;
	TH1F* h_charge_mis_mu;
	TH1F* h_mistag_mu;
	
	TH1F* h_correct_el;
	TH1F* h_charge_mis_el;
	TH1F* h_mistag_el;

	TH2D* h_chi2min_mass_el;
	TH2D* h_chi2min_mass_mu;
	TH2D* h_chi2min_mass_t;

	file_name = "rootFile/" + file_name;
    

	TFile* f = new TFile(file_name.c_str());		//if we execute it in the directory TopCPViolation
	f->GetObject("h_correct_t",h_correct_t);	
	f->GetObject("h_charge_mis_t",h_charge_mis_t);
	f->GetObject("h_mistag_t",h_mistag_t);

	f->GetObject("h_correct_mu",h_correct_mu);
	f->GetObject("h_correct_el",h_correct_el);
	f->GetObject("h_charge_mis_mu",h_charge_mis_mu);
	f->GetObject("h_charge_mis_el",h_charge_mis_el);
	f->GetObject("h_mistag_mu",h_mistag_mu);
	f->GetObject("h_mistag_el",h_mistag_el);

	f->GetObject("h_chi2min_mass_el",h_chi2min_mass_el);
	f->GetObject("h_chi2min_mass_mu",h_chi2min_mass_mu);

	h_chi2min_mass_t = (TH2D*)h_chi2min_mass_mu->Clone();
	h_chi2min_mass_t->Add(h_chi2min_mass_el);

	//normalize
	double no_cor_t = h_correct_t->Integral(0,h_correct_t->GetNbinsX()+1);
	double no_cm_t = h_charge_mis_t->Integral(0,h_charge_mis_t->GetNbinsX()+1);
	double no_mt_t = h_mistag_t->Integral(0,h_mistag_t->GetNbinsX()+1);

	double no_cor_mu = h_correct_mu->Integral(0,h_correct_mu->GetNbinsX()+1);
	double no_cm_mu = h_charge_mis_mu->Integral(0,h_charge_mis_mu->GetNbinsX()+1);
	double no_mt_mu = h_mistag_mu->Integral(0,h_mistag_mu->GetNbinsX()+1);

	double no_cor_el = h_correct_el->Integral(0,h_correct_el->GetNbinsX()+1);
	double no_cm_el = h_charge_mis_el->Integral(0,h_charge_mis_el->GetNbinsX()+1);
	double no_mt_el = h_mistag_el->Integral(0,h_mistag_el->GetNbinsX()+1);

	h_correct_t->Scale( 1./no_cor_t );
	h_charge_mis_t->Scale( 1./no_cm_t );
	h_mistag_t->Scale( 1./no_mt_t );

	h_correct_mu->Scale( 1./no_cor_mu );
	h_charge_mis_mu->Scale( 1./no_cm_mu );
	h_mistag_mu->Scale( 1./no_mt_mu );

	h_correct_el->Scale( 1./no_cor_el );
	h_charge_mis_el->Scale( 1./no_cm_el );
	h_mistag_el->Scale( 1./no_mt_el );


	TCanvas* c = new TCanvas("c");
	c->SetLogy(true);

	h_correct_t->SetStats( false );
	h_charge_mis_t->SetStats( false );
	h_mistag_t->SetStats( false );

	h_correct_mu->SetStats( false );
	h_charge_mis_mu->SetStats( false );
	h_mistag_mu->SetStats( false );
	h_correct_el->SetStats( false );
	h_charge_mis_el->SetStats( false );
	h_mistag_el->SetStats( false );

	h_chi2min_mass_t->SetStats(false);

	
	h_correct_t->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_t->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_t->SetFillColorAlpha(kRed,0.1);

	h_correct_mu->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_mu->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_mu->SetFillColorAlpha(kRed,0.1);
	h_correct_el->SetFillColorAlpha(kBlue,0.1);
	h_charge_mis_el->SetFillColorAlpha(kGreen+1,0.1);
	h_mistag_el->SetFillColorAlpha(kRed,0.1);


	h_correct_t->SetFillStyle(4050);
	h_charge_mis_t->SetFillStyle(4050);
	h_mistag_t->SetFillStyle(4050);

	h_correct_mu->SetFillStyle(4050);
	h_charge_mis_mu->SetFillStyle(4050);
	h_mistag_mu->SetFillStyle(4050);
	h_correct_el->SetFillStyle(4050);
	h_charge_mis_el->SetFillStyle(4050);
	h_mistag_el->SetFillStyle(4050);


	h_correct_t->SetLineColor(kBlue);
	h_charge_mis_t->SetLineColor(kGreen+1);
	h_mistag_t->SetLineColor(kRed);

	h_correct_mu->SetLineColor(kBlue);
	h_charge_mis_mu->SetLineColor(kGreen+1);
	h_mistag_mu->SetLineColor(kRed);
	h_correct_el->SetLineColor(kBlue);
	h_charge_mis_el->SetLineColor(kGreen+1);
	h_mistag_el->SetLineColor(kRed);


	h_correct_t->SetLineWidth(2);
	h_charge_mis_t->SetLineWidth(2);
	h_mistag_t->SetLineWidth(2);

	h_correct_mu->SetLineWidth(2);
	h_charge_mis_mu->SetLineWidth(2);
	h_mistag_mu->SetLineWidth(2);
	h_correct_el->SetLineWidth(2);
	h_charge_mis_el->SetLineWidth(2);
	h_mistag_el->SetLineWidth(2);

	/*
	h_correct->Draw("HIST");
	c->Print("chi2_value_tt.pdf(","Title:Correct Matching case");
	h_charge_mis->Draw("HIST");
	c->Print("chi2_value_tt.pdf","Title:Charge Misidentified case");
	h_mistag->Draw("HIST");
	c->Print("chi2_value_tt.pdf","Title:Mistag case");
	*/


	double l_x_m = 0.29;
    double l_x_M = 0.95-0.34;
    double l_y_m = 0.68;
    double l_y_M = 0.6/0.7-0.05;

	if(file_name.find("MLP")!=string::npos ||file_name.find("BDTG")!=string::npos)
	{
		l_x_m = 0.29;
    	l_x_M = 0.95-0.34;
    	l_y_m = 0.68;
    	l_y_M = 0.6/0.7-0.05;
	}
	else if(file_name.find("BDT")!=string::npos)
	{
		l_x_m = 0.95-0.34;
    	l_x_M = 0.85;
    	l_y_m = 0.68;
    	l_y_M = 0.6/0.7-0.05;
	}
	
	auto legend1 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend1->SetTextFont( 43 );
	legend1->SetTextSize( 13 );
	legend1->SetBorderSize( 0 );

	legend1->AddEntry( (TObject*)0, "Muon Channel" , "" );	
	legend1->AddEntry( h_correct_mu , "Correct Matching" );
	legend1->AddEntry( h_charge_mis_mu , "b#bar{b} Misidentified" );
	legend1->AddEntry( h_mistag_mu , "Mistag" );

	auto legend2 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend2->SetTextFont( 43 );
	legend2->SetTextSize( 13 );
	legend2->SetBorderSize( 0 );
	
	legend2->AddEntry( (TObject*)0, "Electron Channel" , "" );	
	legend2->AddEntry( h_correct_el , "Correct Matching" );
	legend2->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend2->AddEntry( h_mistag_el , "Mistag" );
    
    auto legend3 = new TLegend(l_x_m,l_y_m,l_x_M,l_y_M);	
	legend3->SetTextFont( 43 );
	legend3->SetTextSize( 13 );
	legend3->SetBorderSize( 0 );
	
	legend3->AddEntry( (TObject*)0, "" , "" );	
	legend3->AddEntry( h_correct_el , "Correct Matching" );
	legend3->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend3->AddEntry( h_mistag_el , "Mistag" );
	
	h_correct_mu->GetYaxis()->SetTitle( "Ratio" );
	h_correct_mu->GetXaxis()->SetTitle( "#chi^{2}_{min} value" );
	h_correct_mu->GetYaxis()->SetTitleOffset(1.5);
	h_correct_mu->Draw("HIST");
	h_charge_mis_mu->Draw("HIST SAME");
	h_mistag_mu->Draw("HIST SAME");
	legend1->Draw("SAME");
	string name1 = pdf_name + "(";
	c->Print(name1.c_str(),"Title:Muon Channel");

	h_correct_el->GetYaxis()->SetTitle( "Ratio" );
	h_correct_el->GetXaxis()->SetTitle( "#chi^{2}_{min} value" );
	h_correct_el->GetYaxis()->SetTitleOffset(1.5);
	h_correct_el->Draw("HIST");
	h_charge_mis_el->Draw("HIST SAME");
	h_mistag_el->Draw("HIST SAME");
	legend2->Draw("SAME");
    string name2 = pdf_name;
	c->Print(name2.c_str(),"Title:Electron Channel");

	h_correct_t->GetYaxis()->SetTitleOffset(1.5);
	h_correct_t->GetYaxis()->SetTitle( "Ratio" );
	h_correct_t->GetXaxis()->SetTitle( "#chi^{2}_{min} value" );
    
    h_correct_t->Draw("HIST");
	h_charge_mis_t->Draw("HIST SAME");
	h_mistag_t->Draw("HIST SAME");
    legend3->Draw("SAME");
    string name3 = pdf_name;
    c->Print(name3.c_str(),"Title:Total");


    c->SetLogy(false);

    h_chi2min_mass_t->GetYaxis()->SetTitle("#chi^{2}_{min} value");
	h_chi2min_mass_t->GetXaxis()->SetTitle("M_{jjb}(Invariant Mass)");
	h_chi2min_mass_t->GetZaxis()->SetTitle("events No.");
	h_chi2min_mass_t->GetZaxis()->SetLabelSize(0.02);
	h_chi2min_mass_t->GetZaxis()->SetTitleOffset(1.2);
	h_chi2min_mass_t->GetYaxis()->SetTitleOffset(1.2);

    gStyle->SetPalette(kBird);
    h_chi2min_mass_t->Draw("COLZ");
    string name4 = pdf_name + ")";
	c->Print(name4.c_str(),"Title:MVA value - jjb Mass");   
    


	//Save these 4 hist to be a root file
	
	//*****make space free*****//
	
	//delete h_correct_mu;
	//delete h_charge_mis_mu;
	//delete h_mistag_mu;

	//delete h_chi2_data_mu;	

	//delete h_correct_el;
	//delete h_charge_mis_el;
	//delete h_mistag_el;

	//delete h_chi2_data_el;	
	
	delete c;

}


#endif  //PLOT_BBSEP_REAL_NO_H
