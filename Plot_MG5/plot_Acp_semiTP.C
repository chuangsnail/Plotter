#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>

#define YBound 1.0		//if want to see artificial Acp , tune it to be 5.0

using namespace std;

string obs_name[4] = { "O_{3}", "O_{6}", "O_{12}", "O_{13}" };
string y_title = "A'_{cp} [%]";

void PlotAcp( const string& filename, const string& channel );

double GetAcpError( TH1D* p, TH1D* n, int bin );

void exe()
{
	//PlotAcp( "p03_all_MLP_Acp_200107_0621", "t" );
	//PlotAcp( "p03_all_MLP_Acp_200107_0621", "mu" );
	//PlotAcp( "p03_all_MLP_Acp_200107_0621", "el" );
	/*
	PlotAcp( "chi2_Acp_200108_0306", "t" );
	PlotAcp( "chi2_Acp_200108_0306", "mu" );
	PlotAcp( "chi2_Acp_200108_0306", "el" );

	PlotAcp( "p05_0-2_MLP_Acp_200108_0312", "t" );
	PlotAcp( "p05_0-2_MLP_Acp_200108_0312", "mu" );
	PlotAcp( "p05_0-2_MLP_Acp_200108_0312", "el" );
	*/

	/*
	PlotAcp( "chi2_Acp_200108_0516", "t" );
	PlotAcp( "chi2_Acp_200108_0516", "mu" );
	PlotAcp( "chi2_Acp_200108_0516", "el" );
	*/

	/*
	PlotAcp( "p05_0-2_MLP_Acp_200108_0520", "t" );
	PlotAcp( "p05_0-2_MLP_Acp_200108_0520", "mu" );
	PlotAcp( "p05_0-2_MLP_Acp_200108_0520", "el" );
	*/


/*		
	PlotAcp( "p05_all_MLP_Acp_200121_1008", "t" );
	PlotAcp( "p05_all_MLP_Acp_200121_1008", "mu" );
	PlotAcp( "p05_all_MLP_Acp_200121_1008", "el" );
*/

/*	
	PlotAcp( "a05_0-2_MLP_Acp_200122_2333", "t" );
	PlotAcp( "a05_0-2_MLP_Acp_200122_2333", "mu" );
	PlotAcp( "a05_0-2_MLP_Acp_200122_2333", "el" );

	
	PlotAcp( "p05_0-2_MLP_Acp_200109_1433", "t" );
	PlotAcp( "p05_0-2_MLP_Acp_200109_1433", "el" );
	PlotAcp( "p05_0-2_MLP_Acp_200109_1433", "mu" );
	
	PlotAcp( "chi2_Acp_200109_1427", "t" );
	PlotAcp( "chi2_Acp_200109_1427", "mu" );
	PlotAcp( "chi2_Acp_200109_1427", "el" );
*/

/*
	PlotAcp( "chi2_Acp_200108_0516", "t" );
	PlotAcp( "chi2_Acp_200108_0516", "mu" );
	PlotAcp( "chi2_Acp_200108_0516", "el" );
	
	PlotAcp( "p05_0-2_MLP_Acp_200108_0520", "t" );
	PlotAcp( "p05_0-2_MLP_Acp_200108_0520", "mu" );
	PlotAcp( "p05_0-2_MLP_Acp_200108_0520", "el" );
*/
/*
	PlotAcp( "a05_all_MLP_DetBiasAcp_CR_200125_1722", "t" );
	PlotAcp( "a05_all_MLP_DetBiasAcp_CR_200125_1722", "mu" );
	PlotAcp( "a05_all_MLP_DetBiasAcp_CR_200125_1722", "el" );
*/
/*
	PlotAcp( "chi2_DetBiasCR_200125_1748", "t" );
	PlotAcp( "chi2_DetBiasCR_200125_1748", "mu" );
	PlotAcp( "chi2_DetBiasCR_200125_1748", "el" );
*/
/*
	PlotAcp( "chi2_SRAcp_noweight_200125_2109", "t" );
	PlotAcp( "chi2_SRAcp_noweight_200125_2109", "mu" );
	PlotAcp( "chi2_SRAcp_noweight_200125_2109", "el" );
*/
/*
	PlotAcp( "chi2_SRttAcp_200125_2207", "t" );
	PlotAcp( "chi2_SRttAcp_200125_2207", "mu" );
	PlotAcp( "chi2_SRttAcp_200125_2207", "el" );
*/

/*
	PlotAcp( "p05_all_MLP_Acp_200128_1740", "t" );
	PlotAcp( "p05_all_MLP_Acp_200128_1740", "mu" );
	PlotAcp( "p05_all_MLP_Acp_200128_1740", "el" );
*/
/*
	PlotAcp( "p05_all_MLP_DetBiasAcp_CR_200128_1911", "t" );
	PlotAcp( "p05_all_MLP_DetBiasAcp_CR_200128_1911", "mu" );
	PlotAcp( "p05_all_MLP_DetBiasAcp_CR_200128_1911", "el" );
*/
/*
	PlotAcp( "p05_0-2_MLP_DetBiasAcp_CR_200128_1918", "t" );
	PlotAcp( "p05_0-2_MLP_DetBiasAcp_CR_200128_1918", "mu" );
	PlotAcp( "p05_0-2_MLP_DetBiasAcp_CR_200128_1918", "el" );
*/
/*
	PlotAcp( "p05_0-2_MLP_Acp_200128_1947", "t" );
	PlotAcp( "p05_0-2_MLP_Acp_200128_1947", "mu" );
	PlotAcp( "p05_0-2_MLP_Acp_200128_1947", "el" );
*/
/*
	PlotAcp( "a05_all_MLP_DetBiasAcp_CR_200128_2002", "t" );
	PlotAcp( "a05_all_MLP_DetBiasAcp_CR_200128_2002", "mu" );
	PlotAcp( "a05_all_MLP_DetBiasAcp_CR_200128_2002", "el" );
*/
/*
	PlotAcp( "a05_all_MLP_Acp_200128_2030" , "t" );
	PlotAcp( "a05_all_MLP_Acp_200128_2030" , "mu" );
	PlotAcp( "a05_all_MLP_Acp_200128_2030" , "el" );
*/

/*
	PlotAcp( "a05_all_MLP_ChangeInfo_Sample_artificial_Acp", "t" );
	PlotAcp( "a05_all_MLP_ChangeInfo_Sample_artificial_Acp", "mu" );
	PlotAcp( "a05_all_MLP_ChangeInfo_Sample_artificial_Acp", "el" );
*/

//artificial!!
/*
	PlotAcp( "a05_all_MLP_artificial_acp_200131_1506", "t" );
	PlotAcp( "a05_all_MLP_artificial_acp_200131_1506", "mu" );
	PlotAcp( "a05_all_MLP_artificial_acp_200131_1506", "el" );
*/

/*	
	PlotAcp("a05_all_MLP_Acp_200216_2258", "t");
	PlotAcp("a05_all_MLP_Acp_200216_2258", "mu");
	PlotAcp("a05_all_MLP_Acp_200216_2258", "el");
*/
	//PlotAcp("Acp_dtg5-1j","t");
	//PlotAcp("Acp_dtg5-1j","mu");
	//PlotAcp("Acp_dtg5-1j","el");

	//PlotAcp("Acp_sm-1j","t");
	//PlotAcp("Acp_sm-1j","mu");
	//PlotAcp("Acp_sm-1j","el");
	
	//PlotAcp("Acp_dtg10-1j","t");


	//PlotAcp("Acp_semi_2HDM-1j", "t");

	//PlotAcp("TP_Acp_semi_2HDM_NLO-1j","t");
	//PlotAcp("TP_Acp_semi_2HDMtII_NLO-1j","t");
	//PlotAcp("TP_Acp_semi_MSSM_SLHA2-1j","t");
	//PlotAcp("TP_Acp_semi_CEDM50-1j","t");
	//PlotAcp("TP_Acp_semi_CEDM10-1j","t");
	//PlotAcp("TP_Acp_semi_CEDM5-1j","t");
	//PlotAcp("TP_Acp_semi_CEDM2pt5-1j","t");
	//PlotAcp("TP_Acp_semi_CEDM7pt5-1j","t");
	//PlotAcp("TP_Acp_semi_CEDM1-1j","t");

	/*
	PlotAcp("TP_gen_Acp_semi_CEDM5_1j","t");
	PlotAcp("TP_gen_Acp_semi_sm_1j","t");
	PlotAcp("TP_gen_Acp_semi_2HDMtII_NLO_v2_1j","t");
	*/

	//PlotAcp("TP_gen_Acp_semi_CEDM2pt5_1j","t");
	//PlotAcp("TP_gen_Acp_semi_CEDM1_1j","t");

	//PlotAcp("TP_Acp_semi_2HDMtII_NLO_v2_1j","t");

	//PlotAcp("TP_Acp_semi_CEDM2_1j","t");
	//PlotAcp("TP_Acp_semi_CEDM3_1j","t");
	//PlotAcp("TP_Acp_semi_CEDM4_1j","t");

/*
	PlotAcp("TP_gen_Acp_semi_2HDMtII_NLO_v2_1j","t");
	PlotAcp("TP_gen_Acp_semi_2HDMtII_NLO_1j","t");
	PlotAcp("TP_gen_Acp_semi_2HDM_NLO_1j","t");
	PlotAcp("TP_gen_Acp_semi_CEDM3_1j","t");
	PlotAcp("TP_gen_Acp_semi_CEDM4_1j","t");
	PlotAcp("TP_gen_Acp_semi_CEDM7pt5_1j","t");
	PlotAcp("TP_gen_Acp_semi_MSSM_SLHA2_1j","t");
	PlotAcp("TP_gen_Acp_semi_CEDM2_1j","t");
*/
	//PlotAcp("TP_semilep_genAcp_10_6-semi_CEDM5_1j","t");

	PlotAcp("TP_semilep_genAcp_NoSel_test-semi_2HDM_LO_test2","t");
	
}

void PlotAcp( const string& filename, const string& channel = "t" )
{
	string p_name = "h_Obs_" + channel + "_P";
	string n_name = "h_Obs_" + channel + "_N";


	TFile* f = new TFile( (char*)( string("rootFile/") + filename + string(".root") ).c_str() );

	TH1D* h_pos;
	TH1D* h_neg;

	f->GetObject( (char*)p_name.c_str(), h_pos );
	f->GetObject( (char*)n_name.c_str(), h_neg );

	TH1D* num = (TH1D*)h_pos->Clone();
	TH1D* den = (TH1D*)h_pos->Clone();
	
	//optional
	double hand_acp_err[4] = {0.,0.,0.,0.};
	for(int i=0;i<4;i++)
	{	
		hand_acp_err[i] = GetAcpError( num, den, i+2 );
	}	

	num->Add( h_neg, -1 );
	den->Add( h_neg );

	num->Divide( den );
	
	for(int i=2;i<=5;++i){
		cout << "mean:" << num->GetBinContent( i ) << " error:" << num->GetBinError( i ) << endl;
	}

	TH1D* h_acp = new TH1D( "h_acp", "", 4, 0, 4 );
	TH1D* h_error1 = new TH1D( "h_error1", "", 4, 0, 4 );	
	TH1D* h_error2 = new TH1D( "h_error2", "", 4, 0, 4 );

	for(int i=0;i<4;++i)
	{
		//double binerr = num->GetBinError(i+2);
		double binerr = hand_acp_err[i];
		h_acp->SetBinContent( i+1, num->GetBinContent(i+2)*100 );
		h_acp->SetBinError( i+1, binerr*100 );
		h_error1->SetBinContent( i+1, num->GetBinContent(i+2)*100 );
		h_error1->SetBinError( i+1, binerr*100 );
		h_error2->SetBinContent( i+1, num->GetBinContent(i+2)*100 );
		h_error2->SetBinError( i+1, binerr*200 );
	}


	TCanvas* c = new TCanvas();

	h_acp->SetStats( false );
	h_error1->SetStats( false );
	h_error2->SetStats( false );
	h_error1->SetFillColor( kGreen );
	h_error2->SetFillColor( kYellow );

	h_acp->SetMaximum( YBound );
	h_acp->SetMinimum( -1 * YBound );

	for(int i=0;i<4;i++){
		h_acp->GetXaxis()->SetBinLabel( i+1, (char*)obs_name[i].c_str() );
	}
	h_acp->GetYaxis()->SetTitle( (char*)y_title.c_str() );
	
	//TLegend* l = new TLegend(0.6,0.7,0.85,0.85);		//right-top
	TLegend* l = new TLegend(0.6,0.15,0.85,0.3);		//right-bottom
	l->AddEntry( (TObject*)0,"Signal Region", "" );
	if( channel != "t" )
		l->AddEntry( (TObject*)0, (char*)( string("ch-") + channel ).c_str() , "" );
	l->AddEntry( h_acp, "Nominal value", "LEP");
	l->AddEntry( h_error1, "1#sigma stat. error", "F");
	l->AddEntry( h_error2, "2#sigma stat. error", "F");
	l->SetBorderSize( 0 );
	

	TLine* l1 = new TLine(0,0,4,0);

	h_acp->Draw();
	h_error2->Draw( "E2 SAME" );
	h_error1->Draw( "E2 SAME" );
	h_acp->Draw( "EP SAME" );
	l->Draw("SAME");
	l1->Draw("SAME");

	string pdfname = "pdfFile/Acp_" + filename + "_" + channel + ".pdf";
	c->Print( (char*)pdfname.c_str() );
	
}

double GetAcpError( TH1D* p, TH1D* n, int bin )
{
	double Np =  p->GetBinContent( bin );
	double Nn =  n->GetBinContent( bin );
	return sqrt( ( 4 * Np * Nn ) / pow( (Np + Nn), 3 ) );
}
