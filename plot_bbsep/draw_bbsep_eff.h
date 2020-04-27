#ifndef DRAW_BBSEP_EFF
#define DRAW_BBSEP_EFF

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <iterator>
#include <math.h>

#define XaxisName "MVA value"
#define YaxisName "Ratio"

using namespace std;

void draw_eff( const string& filename, string newfile_name )
{

    string post_newfile_name = newfile_name + "_eff.pdf";

	TFile* f = new TFile( filename.c_str() );

    //Get histograms from rootfile

    TH1F* h_correct_t;
    TH1F* h_charge_mis_t;
    TH1F* h_mistag_t;
     
	TH1F* h_correct_mu;
	TH1F* h_charge_mis_mu;
	TH1F* h_mistag_mu;
    
    TH1F* h_correct_el;
    TH1F* h_charge_mis_el;
    TH1F* h_mistag_el;

    f->GetObject("h_correct_t",h_correct_t);
    f->GetObject("h_charge_mis_t",h_charge_mis_t);
    f->GetObject("h_mistag_t",h_mistag_t);

    f->GetObject("h_correct_mu",h_correct_mu);
    f->GetObject("h_charge_mis_mu",h_charge_mis_mu);
    f->GetObject("h_mistag_mu",h_mistag_mu);
    
    f->GetObject("h_correct_el",h_correct_el);
    f->GetObject("h_charge_mis_el",h_charge_mis_el);
    f->GetObject("h_mistag_el",h_mistag_el);
    

    //Get Entries()

    double cor_evt_mu = h_correct_mu->Integral(1,h_correct_mu->GetXaxis()->GetNbins()+1);
    double cmis_evt_mu = h_charge_mis_mu->Integral(1,h_charge_mis_mu->GetXaxis()->GetNbins()+1);
    double mist_evt_mu = h_mistag_mu->Integral(1,h_mistag_mu->GetXaxis()->GetNbins()+1);
    
    double cor_evt_el = h_correct_el->Integral(1,h_correct_el->GetXaxis()->GetNbins()+1);
    double cmis_evt_el = h_charge_mis_el->Integral(1,h_charge_mis_el->GetXaxis()->GetNbins()+1);
    double mist_evt_el = h_mistag_el->Integral(1,h_mistag_el->GetXaxis()->GetNbins()+1);

    double cor_evt_t = h_correct_t->Integral(1,h_correct_t->GetXaxis()->GetNbins()+1);
    double cmis_evt_t = h_charge_mis_t->Integral(1,h_charge_mis_t->GetXaxis()->GetNbins()+1);
    double mist_evt_t = h_mistag_t->Integral(1,h_mistag_t->GetXaxis()->GetNbins()+1);
    
    map<string,double> cor_evt, cmis_evt, mist_evt, total_evt;

    cor_evt["t"] = cor_evt_t;
    cmis_evt["t"] = cmis_evt_t;
    mist_evt["t"] = mist_evt_t;
    total_evt["t"] = cor_evt_t + cmis_evt_t + mist_evt_t;

    cout << cor_evt_t;

    cor_evt["mu"] = cor_evt_mu;
    cmis_evt["mu"] = cmis_evt_mu;
    mist_evt["mu"] = mist_evt_mu;
    total_evt["mu"] = cor_evt_mu + cmis_evt_mu + mist_evt_mu;
    
    cor_evt["el"] = cor_evt_el;
    cmis_evt["el"] = cmis_evt_el;
    mist_evt["el"] = mist_evt_el;
    total_evt["el"] = cor_evt_el + cmis_evt_el + mist_evt_el;
    
    //Make efficiency TH1

    double N_Bins_in_rootfile = (int)h_correct_mu->GetNbinsX();
    double maxX = h_correct_mu->GetXaxis()->GetXmax();
    double minX = h_correct_mu->GetXaxis()->GetXmin();
    
    TH1F* h_eff_cor_t = new TH1F("h_eff_cor_t","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_cmis_t = new TH1F("h_eff_cmis_t","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_mist_t = new TH1F("h_eff_mist_t","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_events_t = new TH1F("h_eff_events_t","",N_Bins_in_rootfile,minX,maxX);

    TH1F* h_eff_cor_mu = new TH1F("h_eff_cor_mu","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_cmis_mu = new TH1F("h_eff_cmis_mu","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_mist_mu = new TH1F("h_eff_mist_mu","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_events_mu = new TH1F("h_eff_events_mu","",N_Bins_in_rootfile,minX,maxX);
    
    TH1F* h_eff_cor_el = new TH1F("h_eff_cor_el","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_cmis_el = new TH1F("h_eff_cmis_el","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_mist_el = new TH1F("h_eff_mist_el","",N_Bins_in_rootfile,minX,maxX);
    TH1F* h_eff_events_el = new TH1F("h_eff_events_el","",N_Bins_in_rootfile,minX,maxX);

    map<string,TH1F*> h_correct, h_charge_mis, h_mistag, h_eff_cor, h_eff_cmis, h_eff_mist, h_eff_events;
    
    h_correct["t"] = h_correct_t;
    h_charge_mis["t"] = h_charge_mis_t;
    h_mistag["t"] = h_mistag_t;
    h_eff_cor["t"] = h_eff_cor_t;
    h_eff_cmis["t"] = h_eff_cmis_t;
    h_eff_mist["t"] = h_eff_mist_t;
    h_eff_events["t"] = h_eff_events_t;

    h_correct["mu"] = h_correct_mu;
    h_charge_mis["mu"] = h_charge_mis_mu;
    h_mistag["mu"] = h_mistag_mu;
    h_eff_cor["mu"] = h_eff_cor_mu;
    h_eff_cmis["mu"] = h_eff_cmis_mu;
    h_eff_mist["mu"] = h_eff_mist_mu;
    h_eff_events["mu"] = h_eff_events_mu;
    
    h_correct["el"] = h_correct_el;
    h_charge_mis["el"] = h_charge_mis_el;
    h_mistag["el"] = h_mistag_el;
    h_eff_cor["el"] = h_eff_cor_el;
    h_eff_cmis["el"] = h_eff_cmis_el;
    h_eff_mist["el"] = h_eff_mist_el;
    h_eff_events["el"] = h_eff_events_el;
    
    /*
    map<string,map<string,TH1F*>*> hist_map;
    hist_map["cor"] = &h_correct;
    hist_map["cmis"] = &h_charge_mis;
    hist_map["mist"] = &h_mistag;
    map<string,map<string,TH1F*>*> hist_eff_map;
    hist_eff_map["cor"] = &h_eff_cor;
    hist_eff_map["cmis"] = &h_eff_cmis;
    hist_eff_map["mist"] = &h_eff_mist;
    */
    
    vector<string> ch = { "t", "mu", "el" };
    vector<string> cases ={ "cor", "cmis", "mist" };
    

    cout << "cor_evt_t : " << cor_evt_t << endl;
    cout << "cmis_evt_t : " << cmis_evt_t << endl;
    cout << "mist_evt_t : " << mist_evt_t << endl;

    
	double binW = h_correct_mu->GetBinWidth(1);
    cout << "binW : " << binW << endl ; 

    for(int i=0;i<(int)ch.size();i++)
    {
        string channel = ch.at(i);
        //use in if binW is 1.

        cout << endl << "Channel : " << channel << endl << endl;
        for(int k=1;k<=N_Bins_in_rootfile;k++)
        {
            int cut = k;
            double no_cor = 0.,no_cmis = 0.,no_mist = 0.;
            double r_cor = 0.,r_cmis = 0.,r_mist = 0.;
            double no_total = 0.;

            no_cor = h_correct[channel]->Integral(1,cut);
            no_cmis = h_charge_mis[channel]->Integral(1,cut);
            no_mist = h_mistag[channel]->Integral(1,cut);

            /*
            for(int r=1;r<=cut;r++)
            {
                no_cor +=  h_correct[channel]->GetBinContent(r);// * binW;
                no_cmis +=  h_charge_mis[channel]->GetBinContent(r);// * binW;
                no_mist +=  h_mistag[channel]->GetBinContent(r);// * binW;
            }
            */
            no_total =  total_evt[channel] - (no_cor + no_cmis + no_mist);
            r_cor = (cor_evt[channel] - no_cor)/no_total;
            r_cmis = (cmis_evt[channel] - no_cmis)/no_total;
            r_mist = (mist_evt[channel] - no_mist)/no_total;
                
            if(channel == "t"){
                cout << "cut(bin) : " << cut << endl;

                cout << "no_cor : " << no_cor << endl;
                cout << "no_cmis : " << no_cmis << endl;
                cout << "no_mist : " << no_mist << endl;
                
                cout << "r_cor : " << r_cor << endl;
                cout << "r_cmis : " << r_cmis << endl;
                cout << "r_mist : " << r_mist << endl;
                cout << "events Eff : " << no_total/total_evt[channel] << endl;
            }

            if(isnan(r_cor) || isnan(r_cmis) || isnan(r_mist))
            {	break;	}
                
            h_eff_events[channel]->SetBinContent(k,no_total/total_evt[channel]);
            h_eff_cor[channel]->SetBinContent(k,r_cor);
            h_eff_cmis[channel]->SetBinContent(k,r_cmis);
            h_eff_mist[channel]->SetBinContent(k,r_mist);
            

                
        }
    }
    
    for(int i=0;i<(int)ch.size();i++)
    {
        string channel = ch.at(i);
        
        h_eff_cor[channel]->SetFillStyle(4050);
        h_eff_cmis[channel]->SetFillStyle(4050);
        h_eff_mist[channel]->SetFillStyle(4050);
        
        h_eff_cor[channel]->SetLineColor(kBlue);
        h_eff_cmis[channel]->SetLineColor(kGreen+1);
        h_eff_mist[channel]->SetLineColor(kRed);
        h_eff_events[channel]->SetLineColor(1);
        
        h_eff_cor[channel]->SetLineWidth(2);
        h_eff_cmis[channel]->SetLineWidth(2);
        h_eff_mist[channel]->SetLineWidth(2);
        h_eff_events[channel]->SetLineWidth(3);
        
        h_eff_cor[channel]->SetFillColorAlpha(kBlue,0.);
        h_eff_cmis[channel]->SetFillColorAlpha(kGreen+1,0.);
        h_eff_mist[channel]->SetFillColorAlpha(kRed,0.);
        
        h_eff_cor[channel]->SetStats(false);
        h_eff_cmis[channel]->SetStats(false);
        h_eff_mist[channel]->SetStats(false);
        h_eff_events[channel]->SetStats(false);
        
    }
    

    //for t11

    //TLegend* l1 = new TLegend(0.65,0.72,0.84,0.9);
    TLegend* l1 = new TLegend(0.65,0.55,0.8,0.74);
    l1->SetBorderSize(0);
    l1->AddEntry(h_eff_events_mu,"Event Efficiency");
    l1->AddEntry(h_eff_cor_mu,"Correct Matching");
    l1->AddEntry(h_eff_cmis_mu,"Charge Misidentified");
    l1->AddEntry(h_eff_mist_mu,"Mistag");
    
    //TLegend* l2 = new TLegend(0.65,0.72,0.84,0.9);
    TLegend* l2 = new TLegend(0.65,0.55,0.8,0.74);
    l2->SetBorderSize(0);
    l2->AddEntry(h_eff_events_el,"Event Efficiency");
    l2->AddEntry(h_eff_cor_el,"Correct Matching");
    l2->AddEntry(h_eff_cmis_el,"b#bar{b} Misidentified");
    l2->AddEntry(h_eff_mist_el,"Mistag");

    //TLegend* l3 = new TLegend(0.65,0.72,0.84,0.9);
    TLegend* l3 = new TLegend(0.65,0.55,0.8,0.74);
    l3->SetBorderSize(0);
    l3->AddEntry(h_eff_events_t,"Event Efficiency");
    l3->AddEntry(h_eff_cor_t,"Correct Matching");
    l3->AddEntry(h_eff_cmis_t,"b#bar{b} Misidentified");
    l3->AddEntry(h_eff_mist_t,"Mistag");


    //for t13
/*

    TLegend* l1 = new TLegend(0.65,0.55,0.8,0.74);
    l1->SetBorderSize(0);
    l1->AddEntry(h_eff_events_mu,"Event Efficiency");
    l1->AddEntry(h_eff_cor_mu,"Correct Matching");
    l1->AddEntry(h_eff_cmis_mu,"b#bar{b} Misidentified");
    l1->AddEntry(h_eff_mist_mu,"Mistag");
    
    TLegend* l2 = new TLegend(0.65,0.55,0.8,0.74);
    l2->SetBorderSize(0);
    l2->AddEntry(h_eff_events_el,"Event Efficiency");
    l2->AddEntry(h_eff_cor_el,"Correct Matching");
    l2->AddEntry(h_eff_cmis_el,"b#bar{b} Misidentified");
    l2->AddEntry(h_eff_mist_el,"Mistag");

    TLegend* l3 = new TLegend(0.65,0.55,0.8,0.74);
    l3->SetBorderSize(0);
    l3->AddEntry(h_eff_events_t,"Event Efficiency");
    l3->AddEntry(h_eff_cor_t,"Correct Matching");
    l3->AddEntry(h_eff_cmis_t,"b#bar{b} Misidentified");
    l3->AddEntry(h_eff_mist_t,"Mistag");
*/

    TCanvas* c = new TCanvas("c");
    
    c->SetGrid();                     //To set grid on the pad
    
    h_eff_events_t->GetXaxis()->SetTitle(XaxisName);
    h_eff_events_t->GetYaxis()->SetTitle("Ratio");

    h_eff_events_mu->GetXaxis()->SetTitle(XaxisName);
    h_eff_events_mu->GetYaxis()->SetTitle("Ratio");
    
    h_eff_events_el->GetXaxis()->SetTitle(XaxisName);
    h_eff_events_el->GetYaxis()->SetTitle("Ratio");
    

    h_eff_events_t->Draw("C");       //"C" means drawing a histogram in a curve way
    h_eff_cor_t->Draw("C SAME");
    h_eff_cmis_t->Draw("C SAME");
    h_eff_mist_t->Draw("C SAME");
    l3->Draw("SAME");
    //h_eff_events_mu->GetYaxis()->SetRange(0.,1.);
    h_eff_events_t->SetMaximum(1.);
    h_eff_events_t->SetMinimum(0.);

    string name1 = post_newfile_name + "(";
    c->Print(name1.c_str(),"Title:Total");

    h_eff_events_mu->Draw("C");       //"C" means drawing a histogram in a curve way
    h_eff_cor_mu->Draw("C SAME");
    h_eff_cmis_mu->Draw("C SAME");
    h_eff_mist_mu->Draw("C SAME");
    l1->Draw("SAME");
    //h_eff_events_mu->GetYaxis()->SetRange(0.,1.);
    h_eff_events_mu->SetMaximum(1.);
    h_eff_events_mu->SetMinimum(0.);
    
    string name2 = post_newfile_name;
    c->Print(name2.c_str(),"Title:Muon Channel");
    
    h_eff_events_el->Draw("C");
    h_eff_cor_el->Draw("C SAME");
    h_eff_cmis_el->Draw("C SAME");
    h_eff_mist_el->Draw("C SAME");
    l2->Draw("SAME");
    h_eff_events_el->SetMaximum(1.);
    h_eff_events_el->SetMinimum(0.);

    string name3 = post_newfile_name + ")";
    c->Print(name3.c_str(),"Title:Electron Channel");


	string rootfile_name = newfile_name + "_eff.root";
    TFile* f_out = new TFile( (char*)rootfile_name.c_str(),"recreate" );
	
	h_eff_events_t->Write();
	h_eff_events_mu->Write();
	h_eff_events_el->Write();

	f_out->Close();


    f->Close();

    
    
    /*
    delete h_eff_cor_mu;
    delete h_eff_cmis_mu;
    delete h_eff_mist_mu;
    delete h_eff_events_mu;
    
    delete h_eff_cor_el;
    delete h_eff_cmis_el;
    delete h_eff_mist_el;
    delete h_eff_events_el;
    */
    
    
}

#endif 	//DRAW_BBSEP_EFF
