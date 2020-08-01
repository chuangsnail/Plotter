#ifndef PLOTTER_H
#define PLOTTER_H

#include <iostream>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "string.h"
#include "Hists.h"

#define SYST_NO 5
#define DEV_NO 2

using namespace std;
//std::to_string()
//Drawing

void Make_Unc_TH1( const string& root_file, const string& unc, const string& option );
TH1F* GetMCAll( const string& filename, const string& option );
TH1F* ConvertErrorTH1( TH1* h_err );
void MergeSystTH1( const string& var_name );


string syst_name[SYST_NO] = { "JER", "JES", "btag", "pu", "lepsf"};
string dev_name[DEV_NO] = { "up", "down" };

class Plotter
{
public:
	

	vector<int> color_set;

	double BOTPAD_MARGIN_TOP;
	double BOTPAD_MARGIN_BOT;
	double BOTPAD_MARGIN_RIGHT;
	double BOTPAD_MARGIN_LEFT;

	double TOPPAD_MARGIN_TOP;
	double TOPPAD_MARGIN_BOT;
	double TOPPAD_MARGIN_RIGHT;
	double TOPPAD_MARGIN_LEFT;

	double LEG_TOP;
	double LEG_BOT;
	double LEG_LEFT;
	double LEG_RIGHT;

	double range_min;
	double range_max;

	double CANVAS_X;
	double CANVAS_Y;

	string x_title_set;

	string opt_tx;

	Plotter()
	{
		color_set.push_back(kRed-4);
		color_set.push_back(kYellow-9);
		color_set.push_back(kBlue-7);
		color_set.push_back(kCyan-3);
		color_set.push_back(kGray+2);
		color_set.push_back(kMagenta);

		BOTPAD_MARGIN_TOP = 0.025;
		BOTPAD_MARGIN_BOT = 0.105/0.3;
		BOTPAD_MARGIN_RIGHT = 0.05;
		BOTPAD_MARGIN_LEFT = 0.13;

		TOPPAD_MARGIN_TOP = 0.1/0.7;
		TOPPAD_MARGIN_BOT = 0.05;
		TOPPAD_MARGIN_RIGHT = 0.05;
		TOPPAD_MARGIN_LEFT = 0.13;

		LEG_TOP = 0.6/0.7-0.05;
		LEG_BOT = 0.4;
		LEG_LEFT = 0.54;
		LEG_RIGHT = 0.95-0.05;

		range_min = 0.;
		range_max = 0.;

		CANVAS_X = 700.;
		CANVAS_Y = 600.;

		opt_tx = "preliminary";
		x_title_set = "";
	}

	void SetXRange( const double m, const double& M )
	{
		range_max = M;
		range_min = m;
	}

	void SetLegXRange( const double m, const double& M )
	{
		LEG_LEFT = m;
		LEG_RIGHT = M;
	}

	void SetLegYRange( const double m, const double& M )
	{
		LEG_BOT = m;
		LEG_TOP = M;
	}

	void SetCanvasRatio( const double x, const double& y )
	{
		CANVAS_X = x;
		CANVAS_Y = y;
	}

	void SetXTitle(const string& t)
	{
		x_title_set = t;
	}

	TPad* GetBotPad();
	TPad* GetTopPad();
	TLegend* GetLegend();
	void SaveToPDF(TCanvas* c,const string& filename);
	TCanvas* Plot_DataMC(TCanvas* c, TH1F* h_data ,vector<TH1F*>& h_mcs ,const vector<string>& histo_names,vector<string>& text);
	void Plot_Stack( const string& fname, vector<TH1F*>& h_mu, vector<TH1F*>& h_el );

};

							    
TPad* 
Plotter::GetBotPad()
{
    TPad* bot = new TPad( "botpad", "", 0., 0., 1., 0.3 );
	bot->SetTicks( 1, 1 );
	bot->SetTopMargin( BOTPAD_MARGIN_TOP );
	bot->SetLeftMargin( BOTPAD_MARGIN_LEFT );
	bot->SetRightMargin( BOTPAD_MARGIN_RIGHT );
	bot->SetBottomMargin( BOTPAD_MARGIN_BOT );

	return bot;
}

TPad* 
Plotter::GetTopPad()
{
	TPad* top = new TPad( "toppad", "" , 0, 0.3 , 1., 1.0 );//(x_low,y_low,x_up,y_up)
	top->SetTicks( 1, 1 );
	top->SetBottomMargin( TOPPAD_MARGIN_BOT );
	top->SetLeftMargin( TOPPAD_MARGIN_LEFT );
	top->SetRightMargin( TOPPAD_MARGIN_RIGHT );
	top->SetTopMargin( TOPPAD_MARGIN_TOP );

	return top;
}

TLegend* 
Plotter::GetLegend()
{
	//auto legend = new TLegend(0.54,0.4,0.95,0.6/0.7);		//the (0.95,0.6/0.7) is to match the toppad's margin (0.05,0.1/0.7)
	auto legend = new TLegend(LEG_LEFT,LEG_BOT,LEG_RIGHT,LEG_TOP);		//the (0.95,0.6/0.7) is to match the toppad's margin (0.05,0.1/0.7)
	//auto legend = new TLegend(0.2,0.4,0.5,0.6/0.7-0.05);
	legend->SetTextFont( 43 );
	legend->SetTextSize( 16 );
	legend->SetBorderSize( 0 );
	//legend->SetFillColorAlpha( 0, 0 );
	
	return legend;
}

void 
Plotter::SaveToPDF(TCanvas* c,const string& filename)
{	
	c->Print( filename.c_str() );
}

TCanvas* 
Plotter::Plot_DataMC(TCanvas* c, TH1F* h_data ,vector<TH1F*>& h_mcs ,const vector<string>& histo_names,vector<string>& text)
//histo_names need to be {data_name , MC1_name , MC2_name , ......}
{
	//Setting and declaring
	//string stack_cons = title + ";" + " " + ";Events(No.)";	//if we want title, use this!
	
	string stack_cons = ";;Events(No.)";
		
	THStack* stack_MC = new THStack(" ",stack_cons.c_str());
	
	if( range_min == 0. && range_max == 0. )
	{
	}
	else
	{
		for(int i=0;i<(int)h_mcs.size();i++){
			h_mcs[i]->GetXaxis()->SetRangeUser(range_min,range_max);
		}
		h_data->GetXaxis()->SetRangeUser(range_min,range_max);
	}

	for(int i=0;i<(int)h_mcs.size();i++){
		stack_MC->Add(h_mcs[i]);
	}
	
	h_data->SetMarkerColor(1);
	h_data->SetMarkerSize(1);
	h_data->SetMarkerStyle(21);

	
	for(int i=0;i<(int)h_mcs.size();i++){
		h_mcs[i]->SetMarkerColor(color_set[i]);
		h_mcs[i]->SetMarkerStyle(21);
		h_mcs[i]->SetFillColor(color_set[i]);
	}

	auto legend = GetLegend();
	
	//string lumi_info = "Luminosity : 35.9fb^{-1}" ;
	//legend->AddEntry( (TObject*)0, lumi_info.c_str() , "" );
	
	for(int i=0;i<(int)text.size();i++)
	{
		legend->AddEntry( (TObject*)0, text[i].c_str() , "" );
	}
	legend->AddEntry( (TObject*)0, " " , "" );	
	legend->AddEntry( h_data , histo_names[0].c_str() );
	for(int i=0;i<(int)h_mcs.size();i++){
		legend->AddEntry( h_mcs[i] , histo_names[i+1].c_str() , "F" );
	}

	//Start Drawing

	TGaxis::SetMaxDigits(3);
	
	c->cd();

	TPad* top = GetTopPad();
	top->Draw();
	top->cd();

	TLatex tl;
	tl.SetNDC(true);
	tl.SetTextFont(43);
	tl.SetTextSize(22);
	tl.SetTextAlign(13);

	stack_MC->SetMaximum( 1.5 * stack_MC->GetMaximum() );
	h_data->SetMaximum( 1.5 * h_data->GetMaximum() );
	h_data->SetStats(false);

	string x_title = string(h_data->GetXaxis()->GetTitle());
	h_data->GetXaxis()->SetTitle("");

	h_data->SetMarkerSize( 0.75 );

	h_data->Draw("P E");
	stack_MC->Draw("HIST same");
	h_data->Draw("P E same");
	h_data->Draw("axis same");
	legend->Draw("same");

	tl.DrawLatex(0.13+0.04,0.9-0.1,"#bf{CMS}");

	if( opt_tx == "preliminary" )
		tl.DrawLatex(0.13+0.04,0.9-0.1-33./600.,"#it{Preliminary}");
	else if( opt_tx == "simulation" )
		tl.DrawLatex(0.13+0.04,0.9-0.1-33./600.,"#it{Simulation}");
	
	stack_MC->GetYaxis()->SetTitleOffset( 1.7 );	//to put yaxis title left a little
	//stack_MC->GetYaxis()->TGaxis::SetMaxDigits(4);

	c->cd();	//c->cd(0);

	TPad* bot = GetBotPad();
	bot->Draw();
	bot->cd();

	//double xmin = h_data->GetXaxis()->GetXmin();
	//double xmax = h_data->GetXaxis()->GetXmax();
	
	double xmin = range_min;
	double xmax = range_max;
	if( range_min == 0. && range_max == 0. )
	{
		xmin = h_mcs.at(0)->GetXaxis()->GetXmin();
		xmin = h_mcs.at(0)->GetXaxis()->GetXmax();
	}
	
	TLine* line       = new TLine( xmin, 1.0, xmax, 1.0 );
	TLine* upper_line = new TLine( xmin, 1.5, xmax, 1.5 );
	TLine* lower_line = new TLine( xmin, 0.5, xmax, 0.5 );
	
	//Make the TH1 to store the stacked MC information (because the THStack cannot be divide by TH1,so change it to TH1)
	int XbinsNo = h_data->GetXaxis()->GetNbins();
	TH1F* h_stack_MC= new TH1F("h_stack_MC","hstack in type TH1F",XbinsNo,xmin,xmax);	//h_result_ch_el (MC hist)
	
	for(int i=0;i<(int)h_mcs.size();i++){
		h_stack_MC->Add( h_mcs[i] );
	}

	TH1F* result = (TH1F*)( h_data->Clone() );
	result->Divide( h_stack_MC );

	for( int i = 0; i < h_data->GetNcells(); ++i ){
		if( h_data->GetBinContent( i ) == 0 && h_stack_MC->GetBinContent( i ) == 0 ){
		result->SetBinContent( i, 1. );
		}
	}

	result->Draw( "EP" );
	upper_line->Draw( "same" );
	lower_line->Draw( "same" );
	line->Draw( "same" );
	
	line->SetLineColor( kRed );
	upper_line->SetLineStyle( 3 );
	lower_line->SetLineStyle( 3 );
			    
	result->SetMaximum( 1.6 );
	result->SetMinimum( 0.4 );
	result->GetYaxis()->SetTitle( "Data/MC" );
	

	result->GetXaxis()->SetLabelFont( 43 );
	result->GetXaxis()->SetTitleFont( 43 );
	result->GetYaxis()->SetTitleFont( 43 );
	result->GetYaxis()->SetLabelFont( 43 );
	result->GetXaxis()->SetLabelSize( 18 );
	result->GetXaxis()->SetTitleSize( 22 );
	result->GetYaxis()->SetLabelSize( 18 );
	result->GetYaxis()->SetTitleSize( 22 );
	
	result->GetYaxis()->SetNdivisions( 503 );
	result->GetXaxis()->SetTitleOffset( 4.0 );
	result->GetYaxis()->SetTitleOffset( 1.2 );

	if( x_title_set != "" )
	{
		x_title = x_title_set;
	}

	result->GetXaxis()->SetTitle( x_title.c_str() );

	result->SetStats( kFALSE );		//make default right upper block off

	return c;
}

//h_mu is { h_MC1_mu, h_MC2_mu, ... , h_Data_mu }
void 
Plotter::Plot_Stack( const string& fname, vector<TH1F*>& h_mu, vector<TH1F*>& h_el )
{

	TCanvas* c = new TCanvas("c","",CANVAS_X,CANVAS_Y);
	
	string filename = fname;
	
	vector<string> hist_name;
	hist_name.push_back("Data");			hist_name.push_back("t#bar{t}");
	hist_name.push_back("Drell-Yan");		hist_name.push_back("W+Jets");
	hist_name.push_back("VV(WW,WZ,ZZ)");	hist_name.push_back("Single top");
	hist_name.push_back("QCD");
	
	//Muon Channel
	
	vector<TH1F*> h_MCs_mu, h_MCs_el;
	for(int i=0;i<(int)h_mu.size()-1;++i)
	{
		h_MCs_mu.push_back( h_mu.at(i) );
	}
	for(int i=0;i<(int)h_el.size()-1;++i)
	{
		h_MCs_el.push_back( h_el.at(i) );
	}	
	
	vector<string> text_mu;
	text_mu.push_back( "Muon channel" );
	text_mu.push_back( "Luminosity : 35.9fb^{-1}" );
	
	vector<string> text_el;
	text_el.push_back( "Electron channel" );
	text_el.push_back( "Luminosity : 35.9fb^{-1}" );
	
	c = Plot_DataMC( c, h_mu.at( (int)h_mu.size()-1 ), h_MCs_mu, hist_name, text_mu );
	
	string filename1 = "pdfFile/" + filename + "_mu.pdf";
	c->Print( filename1.c_str() , "Title:Muon Channel" );

	c->cd();

	c = Plot_DataMC( c, h_el.at( (int)h_el.size()-1 ), h_MCs_el, hist_name, text_el );

	string filename2 = "pdfFile/" + filename + "_el.pdf";
	c->Print( filename2.c_str(), "Title:Electron Channel" );
	
}

void Make_Unc_TH1( const string& root_file, const string& unc, const string& option )
{
	string nom_name = "rootFile/a05_MLP/nominal/SRvars_" + root_file + ".root";
	string unc_name = "rootFile/a05_MLP/" + unc + "/SRvars_" + root_file + ".root";

	TH1F* h_nom_mu = GetMCAll( nom_name, string("mu_"+option) );
	h_nom_mu->SetName("h_nom_mu");
	TH1F* h_unc_mu = GetMCAll( unc_name, string("mu_"+option) );
	h_unc_mu->SetName("h_unc_mu");
	TH1F* h_nom_el = GetMCAll( nom_name, string("el_"+option) );
	h_nom_el->SetName("h_nom_el");
	TH1F* h_unc_el = GetMCAll( unc_name, string("el_"+option) );
	h_unc_el->SetName("h_unc_el");

	h_unc_mu->Add( h_nom_mu, -1. );
	h_unc_mu->Divide( h_nom_mu );
	h_unc_el->Add( h_nom_el, -1. );
	h_unc_el->Divide( h_nom_el );

	string new_filename = "rootFile/a05_MLP_syst/div/" + unc + "_" + root_file + ".root";
	TFile* f_new = new TFile( new_filename.c_str(), "recreate" );
	h_unc_mu->Write();
	h_unc_el->Write();
	f_new->Close();
} 

TH1F* GetMCAll( const string& filename, const string& option )
{
	Hists hists;
	hists.GetObjs( filename , option );

	TH1F* result = new TH1F( "result", "", hists.h_el.at(0)->GetNbinsX() ,hists.h_el.at(0)->GetXaxis()->GetXmin(), hists.h_el.at(0)->GetXaxis()->GetXmax() );

	// size() - 2 means we don't need h_Data and also h_QCD
	if( option.find("NC") != string::npos )
	{
		if( option.find("mu") != string::npos )
		{
			result = (TH1F*)hists.h_mu.at(0)->Clone();
			for(int i=1;i<(int)hists.h_mu.size()-2;++i) {
				result->Add( hists.h_mu.at(i) );
			}
		}
		else if( option.find("el") != string::npos )
		{
			result = (TH1F*)hists.h_el.at(0)->Clone();
			for(int i=1;i<(int)hists.h_el.size()-2;++i) {
				result->Add( hists.h_el.at(i) );
			}
		}
	}
	else if( option.find("1C") != string::npos )
	{
		if( option.find("mu") != string::npos )
		{
			result = (TH1F*)hists.h_mu_c.at(0)->Clone();
			for(int i=1;i<(int)hists.h_mu_c.size()-2;++i) {
				result->Add( hists.h_mu_c.at(i) );
			}
		}
		else if( option.find("el") != string::npos )
		{
			result = (TH1F*)hists.h_el_c.at(0)->Clone();
			for(int i=1;i<(int)hists.h_el_c.size()-2;++i) {
				result->Add( hists.h_el_c.at(i) );
			}
		}
	}
	return result;
}

TH1F* ConvertErrorTH1( TH1* h_err )
{
	TH1F* result = new TH1F();
	result = (TH1F*)h_err->Clone();
	for(int i=1;i<=(int)result->GetXaxis()->GetNbins();++i)
	{
		result->SetBinError(i,result->GetBinContent(i));
		result->SetBinContent(i,0.);
	}

	return result;
}

void MergeSystTH1( const string& var_name )
{
	TH1F* h_result_mu;
	TH1F* h_result_el;

	vector<TH1F*> h_sys_mu, h_sys_el;

	for(int i=0;i<(int)SYST_NO;++i)
	{
		for(int j=0;j<(int)DEV_NO;++j)
		{
			TH1F* h_tmp_mu = new TH1F();
			TH1F* h_tmp_el = new TH1F();

			string SystFileName = "rootFile/a05_MLP_syst/div/" + syst_name[i] + "_" + dev_name[j] + "_" + var_name + ".root";

			cout << "			" << SystFileName << endl;

			TFile* f_tmp = new TFile( SystFileName.c_str() );
			f_tmp->GetObject( "h_unc_mu", h_tmp_mu );
			f_tmp->GetObject( "h_unc_el", h_tmp_el );

			h_sys_mu.push_back(h_tmp_mu);
			h_sys_el.push_back(h_tmp_el);
		}
	}

	// -- init result -- //
	h_result_mu = (TH1F*)h_sys_mu.at(0)->Clone();
	h_result_el = (TH1F*)h_sys_el.at(0)->Clone();

	for(int r=1;r<=(int)h_result_mu->GetXaxis()->GetNbins();++r) {
		h_result_mu->SetBinContent(r,0);
		h_result_mu->SetBinError(r,0);
	}
	for(int r=1;r<=(int)h_result_el->GetXaxis()->GetNbins();++r) {
		h_result_el->SetBinContent(r,0);
		h_result_el->SetBinError(r,0);
	}

	//--- Calculate the total sys ---//

	for(int r=1;r<=(int)h_result_mu->GetXaxis()->GetNbins();++r) {

		double err_up = 0.;
		double err_down = 0.;

		for(int i=0;i<(int)h_sys_mu.size();++i)
		{
			TH1F* h_tmp;
			h_tmp = h_sys_mu.at(i);
		
			double temp_cont = h_tmp->GetBinContent(r);
			if( temp_cont > 0 ) {
				err_up += temp_cont * temp_cont;
			}
			else if( temp_cont < 0 ) {
				err_down += temp_cont * temp_cont;
			}
		}

		err_up = sqrt(err_up);
		err_down = sqrt(err_down);
		
		h_result_mu->SetBinContent(r, (err_up-err_down)/2.);
		h_result_mu->SetBinError(r, (err_up+err_down)/2.);
	}

	for(int r=1;r<=(int)h_result_el->GetXaxis()->GetNbins();++r) {

		double err_up = 0.;
		double err_down = 0.;

		for(int i=0;i<(int)h_sys_el.size();++i)
		{
			TH1F* h_tmp;
			h_tmp = h_sys_el.at(i);
		
			double temp_cont = h_tmp->GetBinContent(r);
			if( temp_cont > 0 ) {
				err_up += temp_cont * temp_cont;
			}
			else if( temp_cont < 0 ) {
				err_down += temp_cont * temp_cont;
			}
		}

		err_up = sqrt(err_up);
		err_down = sqrt(err_down);
		
		h_result_el->SetBinContent(r, (err_up-err_down)/2.);
		h_result_el->SetBinError(r, (err_up+err_down)/2.);
	}

	h_result_mu->SetName("h_UncTotal_mu");
	h_result_el->SetName("h_UncTotal_el");

	string new_filename = "rootFile/a05_MLP_syst/total/" + var_name + ".root";
	TFile* f_new = new TFile( new_filename.c_str(), "recreate" );
	h_result_mu->Write();
	h_result_el->Write();
	f_new->Close();
}

#endif
