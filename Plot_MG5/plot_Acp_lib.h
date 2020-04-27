#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>

#define YBoundExtend 5

using namespace std;

void draw_hist( const string& filename, const string& hist_name ,vector<string>& obs_name );
void draw_known( const vector<double>& mean, const vector<double>& sigma, const vector<string>& obs_name );
void PlotAcp_NC( TH1* h_Acp, const string ouput, const vector<string>& obs_name,const string& y_title = "A_{cp} [%]", const string& option = "2sigma" );
double GetAcpError( TH1D* p, TH1D* n, int bin );
bool draw_ci( const string& obs, vector<double>& mY, vector<double>& eY, const string& opt = "", TF1* f1 = NULL );

void draw_hist( const string& filename, const string& hist_name, vector<string>& obs_name )
{
	TH1F* h = new TH1F();
	string out = filename;
	string FileName = "rootFile/" + filename + ".root";
	TFile* f = new TFile( FileName.c_str() );
	f->GetObject( hist_name.c_str(), h );
	PlotAcp_NC( h, out, obs_name );

}

void draw_known( const string& output, const vector<double>& mean, const vector<double>& sigma, const vector<string>& obs_name )
{
	int N_Obs = (int)mean.size();
	TH1D* h = new TH1D( "h_Acp", "", N_Obs, 0, N_Obs );

	for(int i=0;i<(int)N_Obs;++i)
	{
		h->SetBinContent(i+1, mean[i]);
		h->SetBinError(i+1, sigma[i]);
	}
	PlotAcp_NC( h, output, obs_name );

}

//NC means there is no channel seperation
void 
PlotAcp_NC( TH1* h_Acp, const string ouput, const vector<string>& obs_name,const string& y_title = "A_{cp} [%]", const string& option = "2sigma" )
	//const vector<double>& acp_mean, const vector<double>& acp_err )
{
	//optional
	int N_Obs = (int)obs_name.size();

	TH1D* h_acp = new TH1D( "h_acp", "", N_Obs, 0, N_Obs );
	TH1D* h_error1 = new TH1D( "h_error1", "", N_Obs, 0, N_Obs );	
	TH1D* h_error2 = new TH1D( "h_error2", "", N_Obs, 0, N_Obs );

	for(int i=1;i<=N_Obs;++i)
	{
		h_acp->SetBinContent( i, h_Acp->GetBinContent(i)*100 );
		h_error1->SetBinContent( i, h_Acp->GetBinContent(i)*100 );
		h_error2->SetBinContent( i, h_Acp->GetBinContent(i)*100 );
		h_acp->SetBinError( i, h_Acp->GetBinError(i)*100 );
		h_error1->SetBinError( i, h_Acp->GetBinError(i)*100 );
		h_error2->SetBinError( i, h_Acp->GetBinError(i)*200 );

	}


	TCanvas* c = new TCanvas();

	h_acp->SetStats( false );
	h_error1->SetStats( false );
	h_error2->SetStats( false );

	h_error1->SetFillStyle(3244);
	h_error1->SetFillColor(16);
	/*
	h_error1->SetFillColor( kGreen );
	h_error2->SetFillColor( kYellow );
	*/

	//double YBound = YBoundExtend * (h_acp->GetMaximum());
	double YBound = YBoundExtend * (h_acp->GetBinError(1));

	h_acp->SetMaximum( YBound );
	h_acp->SetMinimum( -1 * YBound );

	for(int i=0;i<N_Obs;i++){
		h_acp->GetXaxis()->SetBinLabel( i+1, (char*)obs_name[i].c_str() );
	}
	h_acp->GetYaxis()->SetTitle( (char*)y_title.c_str() );
	
	TLegend* l = new TLegend(0.65,0.72,0.82,0.85);		//right-top
	//TLegend* l = new TLegend(0.65,0.15,0.87,0.27);		//right-bottom
	//l->AddEntry( (TObject*)0,"Signal Region", "" );
	l->AddEntry( h_acp, "Nominal value", "LEP");
	l->AddEntry( h_error1, "1#sigma stat. error", "F");
	
	if( option.find("2") != string::npos ) {
		l->AddEntry( h_error2, "2#sigma stat. error" );
	}
	
	l->SetBorderSize( 0 );
	
	TLine* l1 = new TLine(0,0,N_Obs,0);

	h_acp->Draw();
	if( option.find("2") != string::npos ) {
		h_error2->Draw( "E1 SAME" );
	}
	h_error1->Draw( "E2 SAME" );
	
	h_acp->Draw( "EP SAME" );
	l->Draw("SAME");
	l1->Draw("SAME");

	string pdfname = "pdfFile/Graph_" + ouput + ".pdf";
	c->Print( (char*)pdfname.c_str() );
	
}

double GetAcpError( TH1D* p, TH1D* n, int bin )
{
	double Np =  p->GetBinContent( bin );
	double Nn =  n->GetBinContent( bin );
	return sqrt( ( 4 * Np * Nn ) / pow( (Np + Nn), 3 ) );
}


bool draw_ci( const string& obs, vector<double>& v_mY, vector<double>& v_eY, const string& opt = "", TF1* f1 = NULL )
{
	const int N = 11;
	if( v_mY.size() != N || v_eY.size() != N ) return false;

	if( opt.find("fit") != string::npos )
	{
		if(f1 == NULL) {
			cerr << "draw fitting with no TF1 input!" << endl;
			return false;
		}
	}

	TCanvas* c = new TCanvas("c","");
	c->GetFrame()->SetFillColor(50);
	c->SetGrid();
	
	double mX[N] = { 0., 0.5, 1., 1.5, 2., 2.5, 3., 3.5, 4., 4.5, 5. };
	double eX[N] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
	
	//event No for j1 GVSel semi selection
	double N_events1[N] = {1345609,1347895,1352213,1354999,1366467,1375350,1386790,1393409,1405564,1419164,1423011};
	//event No for dq GVSel semi selection
	double N_events2[N] = {672121,676274,677007,678180,685544,688145,692817,697364,704486,713201,710735};
	//event No for B1998Sel semi selection
	double N_events3[N] = {672121,676274,677007,678180,685544,688145,692817,697364,704486,713201,710735};

	double N_events[N] = {1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.};

	if( opt.find("evt_GV_j1_semi") != string::npos )
	{
		for(int i=0;i<N;++i) {
			N_events[i] = N_events1[i];
		}
	}
	else if( opt.find("evt_GV_dq_semi") != string::npos )
	{
		for(int i=0;i<N;++i) {
			N_events[i] = N_events2[i];
		}
	}
	else if( opt.find("evt_B1998_semi") != string::npos )
	{
		for(int i=0;i<N;++i) {
			N_events[i] = N_events3[i];
		}
	}


	double event_cor[N] = {1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.};
	for(int i=1;i<N;++i) {
		event_cor[i] = (double)N_events[i] / (double)N_events[0];
	}
	for(int i=1;i<N;++i) {
		v_mY[i] *= event_cor[i];
	}

	//XsecRatio

	//for SM and CEDMs'
	if( opt.find("Xsec") != string::npos ) {
		double XsecRatio[N] = {1.,0.925581,0.959632,1.016911,1.098314,1.204604,1.337439,1.498389,1.689288,1.912756,2.171060};
		for(int i=0;i<N;++i) {
			v_mY[i] = v_mY[i] * XsecRatio[i];
		}
	}

	double mY[N];
	double eY[N];
	
	for(int i=0;i<N;++i) {
		mY[i] = v_mY[i];
		eY[i] = v_eY[i];
	}


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
   	gr->GetXaxis()->SetTitleOffset(1.2);
   	gr->GetYaxis()->SetTitleOffset(1.2);
   	gr->GetYaxis()->SetTitle("A_{cp}");
   	gr->GetXaxis()->CenterTitle();
   	gr->GetYaxis()->CenterTitle();
   	
   	if( opt.find("fit") != string::npos ) {
	   	f1->SetLineColor(50);
	   	f1->SetFillColor(50);
	   	f1->SetMarkerColor(50);
	   	f1->SetLineStyle(2);
   		//f1->SetLineWidth(5);
	}

/*
	TMultiGraph  *mg  = new TMultiGraph();
	mg->SetTitle(obs.c_str());
   	mg->Add(gr);
   	mg->Add(gr2);
   	mg->GetXaxis()->SetTitle("d_{t}^{g}");
   	mg->GetXaxis()->SetTitleOffset(1.2);
   	mg->GetYaxis()->SetTitle("A_{cp}");
   	mg->GetYaxis()->SetTitleOffset(1.2);
   	mg->GetXaxis()->CenterTitle();
   	mg->GetYaxis()->CenterTitle();
 */  	

   	TLegend* l = new TLegend(0.15,0.18,0.3,0.3);	//left down
   	//TLegend* l = new TLegend(0.15,0.7,0.3,0.82);	//left up
   	//l->AddEntry( (TObject*)0, " " , "" );
   	l->AddEntry(gr,"j_{1}","lep");
   	l->SetTextFont( 43 );
	l->SetTextSize( 16 );
	l->SetBorderSize( 1 );

   	gr->Draw("AP");
   	l->Draw("same");

   	if( opt.find("fit") != string::npos )
   	{ f1->Draw("same"); }

   	//gr->Draw("AP");
   	//gr2->Draw("AP");
   	
   	//l->Draw("same");

	string FileName = "pdfFile/ci_" + obs + ".pdf";
	c->Print( (char*)FileName.c_str() );

	return true;
}

