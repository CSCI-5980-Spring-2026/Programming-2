/* Programming 2: Runtime Engine Architecture
 * CSCI 5980, Spring 2026, University of Minnesota
 * Instructor: Evan Suma Rosenberg <suma@umn.edu>
 * License: Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International
 */ 

#include <GopherEngine/Core/MainLoop.hpp>
using namespace GopherEngine;

#include <iostream>

class GopherEngineTest: public MainLoop
{
	public:
		GopherEngineTest();
		~GopherEngineTest();
	private:
		void initialize() override;
};

GopherEngineTest::GopherEngineTest() 
{

}

GopherEngineTest::~GopherEngineTest()
{

}

void GopherEngineTest::initialize() {
	window_.set_title("GopherEngine Test Application");
}

int main()
{
	GopherEngineTest app;
	return app.run();
}