#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>

#define YBound 1.0		//if want to see artificial Acp , tune it to be 5.0

#define N_Obs 2

#define Output "A1"

#define HISTNAME1 ""
#define HISTNAME2 ""

using namespace std;

//string obs_name[4] = { "O_{3}", "O_{6}", "O_{12}", "O_{13}" };
string obs_name[N_Obs] = { "O_{1}" , "O_{3}" };
string y_title = "A'_{cp} [%]";

double GetAcpError( TH1D* p, TH1D* n, int bin );

void test_exe();
void PlotAcp_NC( TH1* h_Acp, const string ouput, const string& option = "2sigma" );
void Plot_dilep_Acp( const string& input );

void exe()
{
	/*
	Plot_dilep_Acp("TP_gen_Acp_dilep_sm_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM3_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM1_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM5_1j_seperately");

	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM5_1j_directly");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM1_1j_directly");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM3_1j_directly");
	Plot_dilep_Acp("TP_gen_Acp_dilep_sm_1j_directly");
	*/
	
	/*
	Plot_dilep_Acp("TP_gen_Acp_dilep_2HDM_NLO_1j_directly");
	Plot_dilep_Acp("TP_gen_Acp_dilep_2HDMtII_NLO_1j_directly");
	Plot_dilep_Acp("TP_gen_Acp_dilep_MSSM_SLHA2_1j_directly");
	
	Plot_dilep_Acp("TP_gen_Acp_dilep_2HDM_NLO_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_2HDMtII_NLO_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_MSSM_SLHA2_1j_seperately");
	*/

	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM2_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM2_1j_directly");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM4_1j_seperately");
	Plot_dilep_Acp("TP_gen_Acp_dilep_CEDM4_1j_directly");

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

void
Plot_dilep_Acp( const string& input )
{
	TH1D* h;
	string filename = "rootFile/" + input + ".root";
	TFile* f = new TFile( (char*)filename.c_str() );
	f->GetObject( "h_Acp_t", h );

	PlotAcp_NC( h, input, "2sigma" );
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

	//h_error1->SetFillStyle(3244);
	//h_error1->SetFillColor(16);
	
	h_error1->SetFillColor( kGreen );
	h_error2->SetFillColor( kYellow );

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
	l->AddEntry( h_error1, "1#sigma stat. error", "F");
	
	if( option.find("2") != string::npos ) {
		l->AddEntry( h_error2, "2#sigma stat. error", "F" );
	}
	l->SetBorderSize( 0 );
	
	TLine* l1 = new TLine(0,0,N_Obs,0);

	h_acp->Draw();
	
	if( option.find("2") != string::npos ) {
		h_error2->Draw( "E2 SAME" );
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
