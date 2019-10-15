// To set this as default, you need a .rootrc file in your home directory,
// containing the following line:
// Rint.Logon: /full/path/to/rootlogon.C
#ifndef ROOTLOGON_C
#define ROOTLOGON_C
// ROOT
#include "TColor.h"
#include "TH1.h"
#include "TLatex.h"
#include "TROOT.h"
#include "TStyle.h"

// Custom color definitions, from
// http://colorbrewer2.org/#type=qualitative&scheme=Paired&n=12
// minus the yellow and re-ordered
int kCustom;
int const NCUSTOMCOLORS = 11;
int const kCustomRed = 0;
int const kCustomDarkBlue = 1;
int const kCustomDarkGreen = 2;
int const kCustomOrange = 3;
int const kCustomPurple = 4;
int const kCustomBrown = 5;
int const kCustomPink = 6;
int const kCustomLightBlue = 7;
int const kCustomLightGreen = 8;
int const kCustomYellow = 9;
int const kCustomLavender = 10;

void rootlogon() {
  // NCC libs
  //gSystem->AddIncludePath("/home/mdi/Code/thesis/code/viewer/include");
  //gSystem->Load("/home/mdi/Code/thesis/code/vbuild/lib/libnccviewer.so");

  // SVSC simulation support libs
  gSystem->AddIncludePath("/data/micah/SVSC/SVSCLibs/Includes/");
  gSystem->Load("/data/micah/SVSC/SVSCLibs/CompiledLibs/"
                "libSupportLib.so");
  gSystem->Load("/data/micah/SVSC/SVSCLibs/CompiledLibs/"
                "libSimulationSupportLib.so");
  gSystem->Load("/data/micah/SVSC/SVSCLibs/CompiledLibs/"
                "libAnalysisLib.so");
  gSystem->Load("/data/micah/SVSC/SVSCLibs/CompiledLibs/"
                "libImagingLib.so");
  gSystem->Load("/data/micah/SVSC/SVSCLibs/CompiledLibs/"
                "libExperimentalDetectorsLib.so");
  
  // DANISim
  //gSystem->AddIncludePath("/home/mdi/Code/danisim/danilib/include");
  //gSystem->Load("/home/mdi/Code/ds-build/danilib/libDANIlib.so");
  
  // Defaults to classic style, but that's OK, we can fix it
  TStyle* novaStyle = new TStyle("novaStyle", "NOvA Style");

  // Centre title
  novaStyle->SetTitleAlign(22);
  novaStyle->SetTitleX(.5);
  novaStyle->SetTitleY(.95);
  novaStyle->SetTitleBorderSize(0);

  // No info box
  novaStyle->SetOptStat(0);

  //set the background color to white
  novaStyle->SetFillColor(10);
  novaStyle->SetFrameFillColor(10);
  novaStyle->SetCanvasColor(10);
  novaStyle->SetPadColor(10);
  novaStyle->SetTitleFillColor(0);
  novaStyle->SetStatColor(10);

  // Don't put a colored frame around the plots
  novaStyle->SetFrameBorderMode(0);
  novaStyle->SetCanvasBorderMode(0);
  novaStyle->SetPadBorderMode(0);

  // Set the default line color for a fit function to be red
  novaStyle->SetFuncColor(kRed);

  // No border on legends
  novaStyle->SetLegendBorderSize(0);

  // Disabled for violating NOvA style guidelines
  // Scientific notation on axes
  TGaxis::SetMaxDigits(3);

  // Axis titles
  novaStyle->SetTitleSize(.055, "xyz");
  novaStyle->SetTitleOffset(.8, "xyz");
  // More space for y-axis to avoid clashing with big numbers
  novaStyle->SetTitleOffset(.8, "y");
  // This applies the same settings to the overall plot title
  novaStyle->SetTitleSize(.055, "");
  novaStyle->SetTitleOffset(.8, "");
  // Axis labels (numbering)
  novaStyle->SetLabelSize(.04, "xyz");
  novaStyle->SetLabelOffset(.005, "xyz");

  // Prevent ROOT from occasionally automatically zero-suppressing
  novaStyle->SetHistMinimumZero();

  // Thicker lines
  novaStyle->SetHistLineWidth(2);
  novaStyle->SetFrameLineWidth(2);
  novaStyle->SetFuncWidth(2);

  // Set the number of tick marks to show
  novaStyle->SetNdivisions(506, "xyz");

  // Set the tick mark style
  novaStyle->SetPadTickX(1);
  novaStyle->SetPadTickY(1);

  // Fonts
  const int kNovaFont = 42;
  novaStyle->SetStatFont(kNovaFont);
  novaStyle->SetLabelFont(kNovaFont, "xyz");
  novaStyle->SetTitleFont(kNovaFont, "xyz");
  novaStyle->SetTitleFont(kNovaFont, ""); // Apply same setting to plot titles
  novaStyle->SetTextFont(kNovaFont);
  novaStyle->SetLegendFont(kNovaFont);

  // Replaced nova "moodier" colors with viridis (112) or cividis (113)
  // viridis is colorblind friendly and cividis is colorblind/color
  // vision deficiency-friendly
  novaStyle->SetPalette(113);

  // Custom colors for plotting a bunch (up to 12, including kBlack) of
  // distinct things, like histograms
  for (int i=0;i < NCUSTOMCOLORS;++i) {
    auto index = TColor::GetFreeColorIndex();
    switch (i) {
      // Red
      case kCustomRed:
        kCustom = index;
        new TColor(index, 227/255., 26/255., 28/255.);
        break;
      // Dark blue
      case kCustomDarkBlue:
        new TColor(index, 31/255., 120/255., 180/255.);
        break;
      // Dark green
      case kCustomDarkGreen:
        new TColor(index, 51/255., 160/255., 44/255.);
        break;
      // Orange
      case kCustomOrange:
        new TColor(index, 255/255., 127/255., 0.);
        break;
      // Purple
      case kCustomPurple:
        new TColor(index, 106/255., 61/255., 154/255.);
        break;
      // Brown
      case kCustomBrown:
        new TColor(index, 177/255., 89/255., 40/255.);
        break;
      // Pink
      case kCustomPink:
        new TColor(index, 251/255., 154/255., 153/255.);
        break;
      // Light blue
      case kCustomLightBlue:
        new TColor(index, 166/255., 206/255., 227/255.);
        break;
      // Light green
      case kCustomLightGreen:
        new TColor(index, 178/255., 223/255., 138/255.);
        break;
      // Yellow (darkish)
      case kCustomYellow:
        new TColor(index, 253/255., 191/255., 111/255.);
        break;
      // Lavender
      case kCustomLavender:
        new TColor(index, 202/255., 178/255., 214/255.);
        break;
    }
  }

  gROOT->SetStyle("novaStyle");
  // Uncomment this line if you want to force all plots loaded from files
  // to use this same style
  gROOT->ForceStyle();
}

// Put a "Preliminary" tag in the corner
void Preliminary() {
  TLatex* prelim = new TLatex(.9, .95, "Preliminary");
  prelim->SetTextColor(kBlue);
  prelim->SetNDC();
  prelim->SetTextSize(2/30.);
  prelim->SetTextAlign(32);
  prelim->Draw();
}

// Put a "Preliminary" tag on the right
void PreliminarySide() {
  TLatex* prelim = new TLatex(.93, .9, "Preliminary");
  prelim->SetTextColor(kBlue);
  prelim->SetNDC();
  prelim->SetTextSize(2/30.);
  prelim->SetTextAngle(270);
  prelim->SetTextAlign(12);
  prelim->Draw();
}

// Put a "Simulation" tag in the corner
void Simulation() {
  TLatex* prelim = new TLatex(.9, .95, "Simulation");
  prelim->SetTextColor(kGray+1);
  prelim->SetNDC();
  prelim->SetTextSize(2/30.);
  prelim->SetTextAlign(32);
  prelim->Draw();
}

// Put a "Simulation" tag on the right
void SimulationSide() {
  TLatex* prelim = new TLatex(.93, .9, "Simulation");
  prelim->SetTextColor(kGray+1);
  prelim->SetNDC();
  prelim->SetTextSize(2/30.);
  prelim->SetTextAngle(270);
  prelim->SetTextAlign(12);
  prelim->Draw();
}

void CenterTitles(TH1* histo) {
  histo->GetXaxis()->CenterTitle();
  histo->GetYaxis()->CenterTitle();
  histo->GetZaxis()->CenterTitle();  
}

#endif
