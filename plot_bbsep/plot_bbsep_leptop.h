/**************************************************************************************
 *
 *	File Name :	plot_bbsep_lt.h
 *	Description : to plot leptonic top distribution under different matching type
 *	Making Date : 191002~
 *	
	use the file after bbsep_mva

 *	Author : Chen-Yu Chuang
 *	using : {exe's name} {rootfile's name} {new pdf's name}
 *
 ****************************************************************************************/

using namespace std;

void plot_bbsep_lt(string file_name, string pdf_name)
{
	pdf_name = pdf_name + "_bbsep_leptop.pdf";

	TH1F* h_correct_mu;
	TH1F* h_charge_mis_mu;
	TH1F* h_mistag_mu;
	
	TH1F* h_correct_el;
	TH1F* h_charge_mis_el;
	TH1F* h_mistag_el;

	TH1F* h_correct_t;
	TH1F* h_charge_mis_t;
	TH1F* h_mistag_t;
    

	TFile* f = new TFile(file_name.c_str());		//if we execute it in the directory TopCPViolation
	f->GetObject("h_lt_correct_mu",h_correct_mu);
	f->GetObject("h_lt_correct_el",h_correct_el);
	f->GetObject("h_lt_charge_mis_mu",h_charge_mis_mu);
	f->GetObject("h_lt_charge_mis_el",h_charge_mis_el);
	f->GetObject("h_lt_mistag_mu",h_mistag_mu);
	f->GetObject("h_lt_mistag_el",h_mistag_el);

	f->GetObject("h_lt_correct_t",h_correct_t);
	f->GetObject("h_lt_charge_mis_t",h_charge_mis_t);
	f->GetObject("h_lt_mistag_t",h_mistag_t);


	TCanvas* c = new TCanvas("c");
	//c->SetLogy(true);

	h_correct_mu->SetStats( false );
	h_charge_mis_mu->SetStats( false );
	h_mistag_mu->SetStats( false );
	
	h_correct_el->SetStats( false );
	h_charge_mis_el->SetStats( false );
	h_mistag_el->SetStats( false );
	

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


	auto legend1 = new TLegend(0.54,0.69,0.95-0.05,0.6/0.7-0.05);	
	legend1->SetTextFont( 43 );
	legend1->SetTextSize( 13 );
	legend1->SetBorderSize( 0 );

	legend1->AddEntry( (TObject*)0, "Muon Channel" , "" );	
	legend1->AddEntry( h_correct_mu , "Correct Matching" );
	legend1->AddEntry( h_charge_mis_mu , "b#bar{b} Misidentified" );
	legend1->AddEntry( h_mistag_mu , "Mistag" );

	auto legend2 = new TLegend(0.54,0.69,0.95-0.05,0.6/0.7-0.05);	
	legend2->SetTextFont( 43 );
	legend2->SetTextSize( 13 );
	legend2->SetBorderSize( 0 );
	
	legend2->AddEntry( (TObject*)0, "Electron Channel" , "" );	
	legend2->AddEntry( h_correct_el , "Correct Matching" );
	legend2->AddEntry( h_charge_mis_el , "b#bar{b} Misidentified" );
	legend2->AddEntry( h_mistag_el , "Mistag" );
    
    auto legend3 = new TLegend(0.54,0.69,0.95-0.05,0.6/0.7-0.05);	
	legend3->SetTextFont( 43 );
	legend3->SetTextSize( 13 );
	legend3->SetBorderSize( 0 );
	
	legend3->AddEntry( (TObject*)0, "" , "" );	
	legend3->AddEntry( h_correct_t , "Correct Matching" );
	legend3->AddEntry( h_charge_mis_t , "b#bar{b} Misidentified" );
	legend3->AddEntry( h_mistag_t , "Mistag" );
    
	
	h_correct_mu->GetYaxis()->SetTitleOffset(1.4);
	h_correct_mu->GetXaxis()->SetTitle( "Leptonic Top Mass(GeV)" );
	
	h_correct_mu->SetMaximum( 1.5 * h_correct_mu->GetMaximum() );
	h_correct_mu->Draw("HIST");
	h_charge_mis_mu->Draw("HIST SAME");
	h_mistag_mu->Draw("HIST SAME");
	legend1->Draw("SAME");
	string name1 = pdf_name + "(";
	c->Print(name1.c_str(),"Title:Muon Channel");

	h_correct_el->GetYaxis()->SetTitleOffset(1.2);
	h_correct_el->GetXaxis()->SetTitle( "Leptonic Top Mass(GeV)" );

	h_correct_el->Draw("HIST");
	h_correct_el->SetMaximum( 1.5 * h_correct_el->GetMaximum() );
	h_charge_mis_el->Draw("HIST SAME");
	h_mistag_el->Draw("HIST SAME");
	legend2->Draw("SAME");
    string name2 = pdf_name;
	c->Print(name2.c_str(),"Title:Electron Channel");

	h_correct_t->GetYaxis()->SetTitleOffset(1.2);
	h_correct_t->GetXaxis()->SetTitle( "Leptonic Top Mass(GeV)" );

	h_correct_t->Draw("HIST");
	h_correct_t->SetMaximum( 1.5 * h_correct_t->GetMaximum() );
	h_charge_mis_t->Draw("HIST SAME");
	h_mistag_t->Draw("HIST SAME");
	legend2->Draw("SAME");
    string name3 = pdf_name + ")";
	c->Print(name3.c_str(),"Title:Total");

}