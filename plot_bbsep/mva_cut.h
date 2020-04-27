#ifndef MVA_CUT_H
#define MVA_CUT_H

#include <vector>
#include <map>
#include <string>
#include "string.h"
#include <iostream>

//constant for legend
#define Xm 0.6
#define XM 0.89
#define Ym 0.6
#define YM 0.85
#define TEXT_FONT 43
#define TEXT_SIZE 16

#define declareTH1(T)						\
TH1F* T = new TH1F("T","",Nbins,xmin,xmax);

#define Normalize(h)						\
h->Scale( 1./(h->Integral(1,h->GetXaxis()->GetNbins()+1)) );


#define InitLegend(l)						\
TLegend* l = new TLegend(Xm,Ym,XM,YM);		\
l->SetTextFont(TEXT_FONT);					\
l->SetTextSize(TEXT_SIZE);					\
l->SetBorderSize(0);

using namespace std;

double InputYGetX( TH1F* h, const double& y )
{
	//use inner linear
	int nbins = (int)h->GetNbinsX();
	double binW = h->GetBinWidth(1);		//if it's a uniform binW histogram
	for(int i=0;i<nbins-1;i++)
	{
		double low = h->GetBinContent(i);
		double high = h->GetBinContent(i+1);
		//if( (low <= y && high >= y) || (low >= y && high <= y) )
		if( low >= y && high <= y )
		{
			double result = binW * i;//((double)i + (y-low)/(high-low));
			return result;
		}
	}
	cerr << y << " is Out of histogram's range!!" << endl;
	return -1.;
}

void NormalizeTH1( TH1F* h )
{
	h->Scale(1./h->Integral(1,h->GetNbinsX()+1));
}

void mva_cut( const string& output_name,const string& ntfilename, const string& efffilename, const string& ntuple_name = "mvav_mass", const string& eff_name = "h_eff_events" )
{
	string nt_mu_name = ntuple_name + "_mu";
	string nt_el_name = ntuple_name + "_el";

	TNtupleD* nt_mu;
	TNtupleD* nt_el;

	string eff_mu_name = eff_name + "_mu";
	string eff_el_name = eff_name + "_el";

	TH1F* eff_mu;
	TH1F* eff_el;

	TFile* fnt = new TFile( (char*)ntfilename.c_str() );
	fnt->GetObject( (char*)nt_mu_name.c_str(), nt_mu );
	fnt->GetObject( (char*)nt_el_name.c_str(), nt_el );

	TFile* feff = new TFile( (char*)efffilename.c_str() );
	feff->GetObject( (char*)eff_mu_name.c_str(), eff_mu );
	feff->GetObject( (char*)eff_el_name.c_str(), eff_el );

	int cut_No = 7;
	double cut_evteff[ 7 ] = { 1., 0.95, 0.9, 0.85, 0.8, 0.75, 0.7 };
	vector<TH1F*> lept_shape_mu, lept_shape_el;

	for(int i=0;i<cut_No;++i)
	{
		double cut_mva_v = InputYGetX( eff_mu, cut_evteff[i] );
		cout << "cut_mva_v at :" << cut_mva_v << endl;
		string hist_name = "h_lept_pdf_mu_" + std::to_string( cut_evteff[i] );
		TH1F* h_new = new TH1F( (char*)hist_name.c_str(), "", 50, 0., 500. );
		int t_entries = (int)nt_mu->GetEntries();
		if(i == 0) { cut_mva_v = 0.;  }

		for(int entry=0;entry<t_entries;++entry)
		{
			nt_mu->GetEntry(entry);
			if( nt_mu->GetArgs()[4] != 6. )		//just look Data's shape
			{ continue; }
			if( nt_mu->GetArgs()[0] >= cut_mva_v  ){
				h_new->Fill( nt_mu->GetArgs()[2], nt_mu->GetArgs()[3] );
			}
		}
		NormalizeTH1( h_new );
		lept_shape_mu.push_back( h_new );
	}

	for(int i=0;i<cut_No;++i)
	{
		double cut_mva_v = InputYGetX( eff_el, cut_evteff[i] );
		cout << "cut_mva_v" << cut_mva_v << endl;
		string hist_name = "h_lept_pdf_el_" + std::to_string( cut_evteff[i] );
		TH1F* h_new = new TH1F( (char*)hist_name.c_str(), "", 50, 0., 500. );
		int t_entries = (int)nt_el->GetEntries();
		if(i == 0) { cut_mva_v = 0.;  }
		
		for(int entry=0;entry<t_entries;++entry)
		{
			nt_el->GetEntry(entry);
			if( nt_el->GetArgs()[4] != 6. )		//just look Data's shape
			{ continue; }
			if( nt_el->GetArgs()[0] >= cut_mva_v  ){
				h_new->Fill( nt_el->GetArgs()[2], nt_el->GetArgs()[3] );
				//cout << "cutNo" << i << endl;
				//cout << "lm:" << nt_el->GetArgs()[2] << "w:" <<nt_el->GetArgs()[3] <<endl;
			}
		}
		NormalizeTH1( h_new );
		lept_shape_el.push_back( h_new );
	}

	int colorset[7] = { kRed, kCyan, kCyan+2, kCyan+4, kBlue, kBlue+2, kBlack };

	TCanvas* c = new TCanvas();
	
	TLegend* l1 = new TLegend(Xm,Ym,XM,YM);
	l1->AddEntry((TObject*)0,"Muon channel","");
	l1->SetTextFont(TEXT_FONT);
	l1->SetTextSize(TEXT_SIZE);
	l1->SetBorderSize(0);

	for(int i=0;i<(int)lept_shape_mu.size();++i){
		string entryname = "Cut on Evt eff:" + to_string( cut_evteff[i] );
		l1->AddEntry( lept_shape_mu.at(i), (char*)entryname.c_str() );
		int color = colorset[i];
		lept_shape_mu.at(i)->SetStats( false );
		lept_shape_mu.at(i)->SetFillColorAlpha(color ,0.);
		lept_shape_mu.at(i)->SetFillStyle(4050);
		lept_shape_mu.at(i)->SetLineColor(color);
		lept_shape_mu.at(i)->SetLineWidth(2);
		lept_shape_mu.at(i)->SetMaximum( 1.5 * lept_shape_mu.at(i)->GetMaximum() );
		lept_shape_mu.at(i)->SetTitle(";M_{lb};PDF");
	}
	lept_shape_mu.at(0)->SetLineWidth(4);
	for(int i=0;i<(int)lept_shape_mu.size();++i){

		if( i == 0){
			lept_shape_mu.at(i)->Draw("HIST");
		}
		else{
			lept_shape_mu.at(i)->Draw("HIST SAME");
		}
	}
	l1->Draw("SAME");
	string output_name1 = output_name + ".pdf(";
	c->Print( (char*)output_name1.c_str(),"Title:Muon Channel" );
	
	TLegend* l2 = new TLegend(Xm,Ym,XM,YM);
	l2->AddEntry((TObject*)0,"Electron channel","");
	l2->SetTextFont(TEXT_FONT);
	l2->SetTextSize(TEXT_SIZE);
	l2->SetBorderSize(0);

	for(int i=0;i<(int)lept_shape_el.size();++i){
		string entryname = "Cut on Evt eff:" + to_string( cut_evteff[i] );
		l2->AddEntry( lept_shape_el.at(i), (char*)entryname.c_str() );	
		int color = colorset[i];
		lept_shape_el.at(i)->SetStats( false );
		lept_shape_el.at(i)->SetFillColorAlpha(color ,0.);
		lept_shape_el.at(i)->SetFillStyle(4050);
		lept_shape_el.at(i)->SetLineColor(color);
		lept_shape_el.at(i)->SetLineWidth(2);
		lept_shape_el.at(i)->SetMaximum( 1.5 * lept_shape_el.at(i)->GetMaximum() );
		lept_shape_el.at(i)->SetTitle(";M_{lb};PDF");
	}
	lept_shape_el.at(0)->SetLineWidth(4);
	for(int i=0;i<(int)lept_shape_el.size();++i){

		if( i == 0){
			lept_shape_el.at(i)->Draw("HIST");
		}
		else{
			lept_shape_el.at(i)->Draw("HIST SAME");
		}
	}
	l2->Draw("SAME");
	string output_name2 = output_name + ".pdf)";
	c->Print( (char*)output_name2.c_str(),"Title:Electron Channel" );
}


#endif  //MVA_CUT_H
