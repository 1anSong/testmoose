#include "testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
testApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

testApp::testApp(InputParameters parameters) : MooseApp(parameters)
{
  testApp::registerAll(_factory, _action_factory, _syntax);
}

testApp::~testApp() {}

void
testApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"testApp"});
  Registry::registerActionsTo(af, {"testApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
testApp::registerApps()
{
  registerApp(testApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
testApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testApp::registerAll(f, af, s);
}
extern "C" void
testApp__registerApps()
{
  testApp::registerApps();
}
