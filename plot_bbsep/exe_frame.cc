#include "draw_bbsep_eff.h"
#include "plot_bbsep_real_no.h"
#include "mva_cut.h"
#include "plot_bbsep_leptop.h"
#include "draw_bbsep_eff_chi2.h"


using namespace std;

void bbsep_all( const string& filename, const string& newfile_name );
void exe()
{
	//bbsep_all("bbsep_t11_MLP_191018_1942.root","t11_MLP");
	//mva_cut( "t11_MLP_CRshape","CR_t11_MLP_all_191128_1544.root","t11_MLP_eff.root" );
	//bbsep_all("bbsep_t13_MLP_191025_0648.root","t13_MLP");
	//mva_cut( "t13_MLP_CRshape","CR_t13_MLP_all_191128_1544.root","t13_MLP_eff.root" );
	//bbsep_all("cor_bbsep_corbb_t20_10_MLP191126_1455.root","t20_MLP");
	//mva_cut("t20_MLP_CRshape","CR_t20_10_191129_1154.root","t20_MLP_eff.root");

	//string t19  = "t19_MLP";
	//bbsep_all("cor_bbsep_t19_MLP_191129_0543.root",t19);
	//mva_cut( string(t19+"_CRshape"),"CR_t19_MLP_191129_1347.root","t19_MLP_eff.root");

	//bbsep_all("cor_bbsep_p01_BDTG_191218_1721.root","p01_BDTG");
	//bbsep_all("cor_bbsep_p01_BDT_191218_1713.root","p01_BDT");

	//bbsep_all("cor_bbsep_a01_BDT_191218_1556.root","a01_BDT");
	//bbsep_all("cor_bbsep_a01_BDTG_191218_1556.root","a01_BDTG");
	//bbsep_all("cor_bbsep_a01_MLP_191218_1538.root","a01_MLP");
	
	//bbsep_all("cor_bbsep_p01_MLP_191218_1660.root","p01_MLP");

	//mva_cut("p01_MLP_CRshape","CR_p01_MLP_191219_1145.root","p01_MLP_eff.root");
	
	//bbsep_all("cor_bbsep_p03_MLP_200102_1609.root","p03_MLP");
	//bbsep_all("cor_bbsep_p03_BDTG_200102_1625.root","p03_BDTG");
	//bbsep_all("corbb_p05_0-2_MLP_200107_1710.root","p05_MLP");
	//bbsep_all("corbb_p05_all_MLP_200121_1007.root","p05_all_MLP");
	//mva_cut("p05_all_MLP_CRshape","","_MLP_eff.root");

	//t13
	bbsep_all("cor_bbsep_t13_BDTG_200723_0350.root","t13_BDTG");
	bbsep_all("cor_bbsep_t13_BDT_200723_0349.root","t13_BDT");
	bbsep_all("cor_bbsep_t13_MLP_200723_0330.root","t13_MLP");

	//a04

	bbsep_all("cor_bbsep_a04_BDT_200717_0453.root","a04_BDT");
	bbsep_all("cor_bbsep_a04_BDTG_200717_0508.root","a04_BDTG");
	bbsep_all("cor_bbsep_a04_MLP_200717_0453.root","a04_MLP");

	//a05
	
	bbsep_all("cor_bbsep_a05_BDT_200717_0342.root","a05_BDT");
	bbsep_all("cor_bbsep_a05_BDTG_200717_0337.root","a05_BDTG");
	bbsep_all("cor_bbsep_a05_MLP_200717_0323.root","a05_MLP");

	//bbsep_all("bbsep_chi2_191025_0539.root","chi2");

}


void bbsep_all( const string& filename, const string& newfile_name )
{
	//draw_eff( filename, newfile_name );
	//plot_bbsep_real_no( filename, newfile_name );
	//plot_bbsep_lt( filename, newfile_name );
	plot_bbsep_mva( filename, newfile_name );

	//plot_bbsep_chi2( filename, newfile_name );
	//draw_eff_chi2( filename, newfile_name );
}

