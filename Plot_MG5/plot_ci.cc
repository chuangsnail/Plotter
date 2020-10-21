#include <string>
#include <iostream>
#include <iomanip>
#include "string.h"

//NOTE O6 O14 times negative


void exe()
{

	TCanvas* c = new TCanvas("c","");
	c->GetFrame()->SetFillColor(50);
	c->SetGrid();
	const int N = 11;
	double mX[N] = { 0., 0.5, 1., 1.5, 2., 2.5, 3., 3.5, 4., 4.5, 5. };
	double eX[N] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};

//double eY[N] = {,,,,,,,,,,};


/*
	// O3, 0j, GVSel

	string obs = "O_{3}";
		// j1
	double mY[N] = {0.000949013,-0.00738856,-0.0150427,-0.0208229,-0.0260519,-0.0284349,-0.0310934,-0.0330291,-0.0333233,-0.0303066,-0.0312612};
	double eY[N] = {0.000862066,0.000861311,0.000859861,0.000858888,0.000855171,0.00085235,0.000848759,0.000846689,0.000843011,0.000839043,0.000837883};
		// dq
	double mY2[N] = {0.000022317,-0.0161355,-0.0282257,-0.0404642,-0.0490093,-0.0529496,-0.0582795,-0.058724,-0.0576818,-0.0541825,-0.0541425};
	double eY2[N] = {0.00121977,0.00121586,0.00121487,0.00121331,0.00120631,0.00120379,0.00119937,0.00119542,0.00118943,0.00118238,0.00118443};

	TF1* f1 = new TF1("f1","-0.0148*x",0.,5.);
	TF1* f2 = new TF1("f2","-0.0258495*x",0.,5.);
*/
/*
	// O6, 0j, GVSel

	string obs = "O_{6}";
		// j1
	double mY[N] = {-0.00179473,0.00482308,0.0103201,0.0140185,0.0174721,0.0177337,0.0188507,0.0206953,0.0205882,0.0192339,0.0197785};
	double eY[N] = {0.000862065,0.000861325,0.000859913,0.000858989,0.000855331,0.00085256,0.000849019,0.000846969,0.000843301,0.000839273,0.000838129};
		// dq
	double mY2[N] = {0.000935843,0.0122229,0.0236763,0.0335457,0.04206,0.0466748,0.0499858,0.0506077,0.0498548,0.0480916,0.0475353};
	double eY2[N] = {0.00121976,0.00121592,0.00121502,0.00121362,0.0012067,0.00120417,0.00119991,0.00119595,0.00118994,0.00118275,0.00118483};

	TF1* f1 = new TF1("f1","0.0095*x",0.,5.);
	TF1* f2 = new TF1("f2","0.0220442*x",0.,5.);
*/
/*
	// O12, 0j, GVSel

	string obs = "O_{12}";
		// j1
	double mY[N] = {-0.000504604,0.000641741,0.00184364,0.00164945,0.00118481,0.00282837,0.00367035,0.00233743,0.00268504,0.00324275,0.00389807};
	double eY[N] = {0.000862066,0.000861335,0.000859957,0.000859073,0.000855461,0.000852691,0.000849164,0.000847148,0.000843477,0.000839424,0.000838287};
		// dq
	double mY2[N] = {-0.00031988,0.000727516,0.00126882,0.00161904,0.000968574,0.0033583,0.00483966,0.00242628,0.00287018,0.0035544,0.00298986};
	double eY2[N] = {0.00121977,0.00121601,0.00121535,0.0012143,0.00120776,0.00120547,0.00120139,0.00119748,0.00119141,0.00118411,0.00118616};

	TF1* f1 = new TF1("f1","0.0018*x",0.,5.);
	TF1* f2 = new TF1("f2","0.00137767*x",0.,5.);
*/
/*
	// O13, 0j, GVSel

	string obs = "O_{13}";
		// j1
	double mY[N] = {0.,0.000029988,-0.000111669,-0.0000243543,-0.000094404,0.000350456,0.000589851,0.000871962,0.000101027,-0.000329772,0.000146872};
	double eY[N] = {0.,0.000861335,0.000859958,0.000859074,0.000855461,0.000852694,0.00084917,0.00084715,0.00084348,0.000839428,0.000838293};
		// dq
	double mY2[N] = {0.,0.0000591476,0.000391429,-0.00066649,-0.000282987,0.000065393,-0.000552816,0.000358493,0.000266861,0.000724901,-0.000651438};
	double eY2[N] = {0.,0.00121601,0.00121536,0.0012143,0.00120776,0.00120548,0.00120141,0.00119749,0.00119142,0.00118412,0.00118617};

	TF1* f1 = new TF1("f1","-0.0*x",0.,5.);
	TF1* f2 = new TF1("f2","0.0000157202*x",0.,5.);
*/
	// O14, 0j, GVSel

	string obs = "O_{14}";
		// j1
	double mY[N] = {0.,-0.000739672,-0.00515377,-0.00690111,-0.00585964,-0.00857527,-0.0082334,-0.0101715,-0.00937844,-0.00910113,-0.0103422};
	double eY[N] = {0.,0.000861335,0.000859958,0.000859074,0.000855461,0.000852694,0.00084917,0.00084715,0.00084348,0.000839428,0.000838293};
		// dq
	double mY2[N] = {0.,0.000733431,0.00118906,-0.0031732,-0.000180878,-0.00158833,-0.00218672,-0.00219111,-0.00175163,-0.00147644,-0.00170106};
	double eY2[N] = {0.,0.00121601,0.00121536,0.0012143,0.00120776,0.00120548,0.00120141,0.00119749,0.00119142,0.00118412,0.00118617};

	TF1* f1 = new TF1("f1","-0.0041*x",0.,5.);
	TF1* f2 = new TF1("f2","-0.00112*x",0.,5.);

//O6 and O14 need to be add minus

	//event No for j1 selection
	double N_events[N] = {1345609,1347895,1352213,1354999,1366467,1375350,1386790,1393409,1405564,1419164,1423011};
	//event No for dq selection
	double N_events2[N] = {672121,676274,677007,678180,685544,688145,692817,697364,704486,713201,710735};

	double event_cor[N] = {0,0,0,0,0,0,0,0,0,0,0};
	for(int i=1;i<N;++i) {
		event_cor[i] = (double)N_events[i] / (double)N_events[0];
		mY[i] *= event_cor[i];
	}
	double event_cor2[N] = {0,0,0,0,0,0,0,0,0,0,0};
	for(int i=1;i<N;++i) {
		event_cor2[i] = (double)N_events2[i] / (double)N_events2[0];
		mY2[i] *= event_cor2[i];
	}

	//XsecRatio

	double XsecRatio[N] = {1.,0.925581,0.959632,1.016911,1.098314,1.204604,1.337439,1.498389,1.689288,1.912756,2.171060};
	for(int i=0;i<N;++i) {
		mY[i] = mY[i] * XsecRatio[i];
		mY2[i] = mY2[i] * XsecRatio[i];
	}
	
	TGaxis::SetMaxDigits(4);
	
	//j1
	TGraphErrors* gr = new TGraphErrors(N,mX,mY,eX,eY);
	//gr->SetTitle("A_{3}");
	//gr->SetTitle("A_");
	gr->SetName("j1");
   	gr->SetMarkerColor(50);
   	gr->SetFillColor(50);
   	gr->SetMarkerSize(1.2);
   	gr->SetMarkerStyle(21);		//triangle
   	gr->GetXaxis()->SetTitle("d_{t}^{g}");
   	gr->GetYaxis()->SetTitle("A_{cp}");
   	//gr->GetXaxis()->CenterTitle();
   	//gr->GetYaxis()->CenterTitle();
   	f1->SetLineColor(50);
   	f1->SetFillColor(50);
   	f1->SetMarkerColor(50);
   	f1->SetLineStyle(2);
   	//f1->SetLineWidth(5);

   	//dq
   	TGraphErrors* gr2 = new TGraphErrors(N,mX,mY2,eX,eY2);
	gr2->SetName("dq");
   	gr2->SetMarkerColor(4);
   	gr2->SetFillColor(4);
   	gr2->SetMarkerSize(1.2);
   	gr2->SetMarkerStyle(21);
   	//gr2->GetXaxis()->SetTitle("d_{t}^{g}");
   	//gr2->GetYaxis()->SetTitle("A_{cp}");
   	//gr2->GetXaxis()->CenterTitle();
   	//gr2->GetYaxis()->CenterTitle();
   	f2->SetLineColor(4);
   	f2->SetFillColor(4);
   	f2->SetMarkerColor(4);
   	f2->SetLineStyle(2);
   	//f2->SetLineWidth(5);

	TMultiGraph  *mg  = new TMultiGraph();
	//mg->SetTitle(obs.c_str());
   	mg->Add(gr);
   	mg->Add(gr2);
   	mg->GetXaxis()->SetTitle("d_{t}^{g}");
   	mg->GetXaxis()->SetTitleOffset(1.2);
   	mg->GetXaxis()->SetLimits(-0.5,5.5);
   	  	
   	mg->GetYaxis()->SetTitle("A_{cp}");
   	mg->GetYaxis()->SetTitleOffset(1.2);

   	//O3
   	//mg->SetMaximum(0.02);
   	//mg->SetMinimum(-0.14);

   	//O6
   	//mg->SetMaximum(0.12);
   	//mg->SetMinimum(-0.02);

   	//O12
   	//mg->SetMaximum(0.0110);
   	//mg->SetMinimum(-0.0025);

   	//O13
   	//mg->SetMaximum(0.0035);
   	//mg->SetMinimum(-0.0035);

   	//O14
   	mg->SetMaximum(0.005);
   	mg->SetMinimum(-0.03);

   	//mg->GetXaxis()->CenterTitle();
   	//mg->GetYaxis()->CenterTitle();
   	
	TLatex tl;
	tl.SetNDC( true );
	tl.SetTextFont(43);
	tl.SetTextSize(22);
	tl.SetTextAlign(33);

   	TLegend* l = new TLegend(0.15,0.15,0.29,0.35);	//left down
   	//TLegend* l = new TLegend(0.15,0.65,0.3,0.85);	//left up
   	//TLegend* l = new TLegend(0.15,0.65,0.29,0.85);	//left up O13
   	//l->AddEntry( (TObject*)0, " " , "" );
   	l->AddEntry( (TObject*)0, obs.c_str(), "");
   	l->AddEntry(gr,"j_{1}","lep");
   	l->AddEntry(gr2,"d-quark","lep");
   	l->SetTextFont( 43 );
	l->SetTextSize( 16 );
	l->SetBorderSize( 1 );

   	mg->Draw("AP");
   	f1->Draw("same");
   	f2->Draw("same");
   	l->Draw("same");
   	tl.DrawLatex(0.89, 0.95, "#bf{MADGRAPH}");
   	

   	//gr->Draw("AP");
   	//gr2->Draw("AP");
   	
   	//l->Draw("same");

	string FileName = "pdfFile/ci_" + obs + ".pdf";
	c->Print( (char*)FileName.c_str() );
}


