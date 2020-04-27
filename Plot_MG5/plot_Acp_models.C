#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>

#define YBound 2.0		//if want to see artificial Acp , tune it to be 5.0

#define N_Obs 5

#define Output "A1"

#define HISTNAME1 "s"
#define HISTNAME2 ""

using namespace std;

//string obs_name[4] = { "O_{3}", "O_{6}", "O_{12}", "O_{13}" };
string obs_name[N_Obs] = { "SM" , "CEDM", "2HDM", "2HDM-tII", "MSSM" };
string y_title = "A'_{cp} [%]";

/*
double mean[N_Obs] = { -0.0010, -0.0039, 0.0012, 0.0002, 0.0017 };
double sigma[N_Obs] = { 0.0027, 0.0027, 0.0027, 0.0027, 0.0027 };
*/

double mean[N_Obs] = { -0.0001, 0.0007, 0.0054, 0.0009, 0.0024 };
double sigma[N_Obs] = { 0.0029, 0.0029, 0.0029, 0.0029, 0.0029 };

void PlotAcp_NC( TH1* h_Acp, const string ouput, const string& option = "2sigma" );

double GetAcpError( TH1D* p, TH1D* n, int bin );

void test_exe();
void draw_known();
void optional_exe( const string& );

void exe()
{
	//draw_known();
	test_exe();
}

void optional_exe( const string& filename )
{
	TH1F* h = new TH1F();
	TFile* f = new TFile( filename.c_str() );
	f->GetObject( HISTNAME1, h );
	PlotAcp_NC( h, "2sigma" );

}

void draw_known()
{
	TH1D* h = new TH1D( HISTNAME1, "", N_Obs, 0, N_Obs );

	for(int i=0;i<(int)N_Obs;++i)
	{
		h->SetBinContent(i+1, mean[i]);
		h->SetBinError(i+1, sigma[i]);
	}
	PlotAcp_NC( h, Output, "2sigma" );

}

void test_exe()
{
	TH1D* h_test = new TH1D( HISTNAME1, "", 2, 0, 2 );
	h_test->Fill(0.,0.01);
	h_test->Fill(1.,-0.005);
	h_test->SetBinError(1, 0.004);
	//h_test->Fill(0.5,0.02);

	PlotAcp_NC( h_test, "test", "2sigma" );

}

//NC means there is no channel seperation
void 
PlotAcp_NC( TH1* h_Acp, const string ouput, const string& option = "2sigma" )
	//const vector<double>& acp_mean, const vector<double>& acp_err )
{
	//optional

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

	h_acp->SetMaximum( YBound );
	h_acp->SetMinimum( -1 * YBound );

	for(int i=0;i<N_Obs;i++){
		h_acp->GetXaxis()->SetBinLabel( i+1, (char*)obs_name[i].c_str() );
	}
	h_acp->GetYaxis()->SetTitle( (char*)y_title.c_str() );
	
	//TLegend* l = new TLegend(0.6,0.7,0.85,0.85);		//right-top
	TLegend* l = new TLegend(0.6,0.15,0.85,0.3);		//right-bottom
	//l->AddEntry( (TObject*)0,"Signal Region", "" );
	l->AddEntry( h_acp, "Nominal value", "LEP");
	l->AddEntry( h_error1, "1#sigma standard error of mean", "F");
	
	if( option.find("2") != string::npos ) {
		l->AddEntry( h_error2, "2#sigma standard error of mean" );
	}
	l->SetBorderSize( 0 );
	
	TLine* l1 = new TLine(0,0,N_Obs,0);

	h_acp->Draw();
	h_error1->Draw( "E2 SAME" );
	
	if( option.find("2") != string::npos ) {
		h_error2->Draw( "E1 SAME" );
	}
	
	h_acp->Draw( "EP SAME" );
	l->Draw("SAME");
	l1->Draw("SAME");

	string pdfname = "Acp_" + ouput + ".pdf";
	c->Print( (char*)pdfname.c_str() );
	
}

double GetAcpError( TH1D* p, TH1D* n, int bin )
{
	double Np =  p->GetBinContent( bin );
	double Nn =  n->GetBinContent( bin );
	return sqrt( ( 4 * Np * Nn ) / pow( (Np + Nn), 3 ) );
}
