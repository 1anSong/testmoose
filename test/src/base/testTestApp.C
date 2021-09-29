//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "testTestApp.h"
#include "testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
testTestApp::validParams()
{
  InputParameters params = testApp::validParams();
  return params;
}

testTestApp::testTestApp(InputParameters parameters) : MooseApp(parameters)
{
  testTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

testTestApp::~testTestApp() {}

void
testTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  testApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"testTestApp"});
    Registry::registerActionsTo(af, {"testTestApp"});
  }
}

void
testTestApp::registerApps()
{
  registerApp(testApp);
  registerApp(testTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
testTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testTestApp::registerAll(f, af, s);
}
extern "C" void
testTestApp__registerApps()
{
  testTestApp::registerApps();
}
