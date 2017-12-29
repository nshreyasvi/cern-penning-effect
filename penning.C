#include <iostream>

#include <TCanvas.h>
#include <TROOT.h>
#include <TApplication.h>

#include "MediumMagboltz.hh"
#include "FundamentalConstants.hh"

using namespace Garfield;

int main(int argc, char * argv[]) {

  // TApplication app("app", &argc, argv);

  ComponentAnalyticField* cmp = new ComponentAnalyticField(); 
  const double rWire = 25.e-4;
  const double rTube = 1.46;
  const double lTube = 10.;
  GeometrySimple* geo = new GeometrySimple()
  SolidTube* tube = new SolidTube(0., 0., 0., rWire, rTube, lTube);
  geo->AddSolid(tube, gas);
  cmp->SetGeometry(geo);
  const double vWire = 3270.;
  const double vTube = 0.;
  cmp->AddWire(0., 0., 2 * rWire, vWire, "s");
  cmp->AddTube(rTube, vTube, 0, "t");
  cmp->AddReadout("s");
  
  const double pressure = 3 * AtmosphericPressure;
  const double temperature = 293.15;
 
  // Setup the gas.
  MediumMagboltz* gas = new MediumMagboltz();
  gas->SetTemperature(temperature);
  gas->SetPressure(pressure);
  gas->SetComposition("Ar", 93., "CO2", 7.);
 
  // Set the field range to be covered by the gas table. 
  const int nFields = 20;
  const double emin =    100.;
  const double emax = 100000.;
  // Flag to request logarithmic spacing.
  const bool useLog = true;
  gas->SetFieldGrid(emin, emax, nFields, useLog); 

  const int ncoll = 10;
  // Switch on debugging to print the Magboltz output.
  gas->EnableDebugging();
  // Run Magboltz to generate the gas table.
  gas->GenerateGasTable(ncoll);
  gas->DisableDebugging();
  // Save the table. 
  gas->WriteGasFile("ar_93_co2_7.gas");

  // app.Run(kTRUE);

}
