#include <node.h>
#include "AStar.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>


using namespace v8;
void AStarJPS(const v8::FunctionCallbackInfo<v8::Value>& args) {

    Isolate* isolate = args.GetIsolate();

    if (args.Length() != 5) {
	isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
	return;
    }

    if (!args[0]->IsArray() || !args[1]->IsNumber() || !args[2]->IsNumber() || !args[3]->IsNumber() || !args[4]->IsNumber() ) {
	isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments")));
	return;
    }

    Local<Array> grid= Local<Array>::Cast(args[0]);

    int startX = args[1]->Int32Value();
    int startY = args[2]->Int32Value();
    int goalX = args[3]->Int32Value();
    int goalY = args[4]->Int32Value();

    int width = 0;
    int height = 0;


    width = grid->Length();
    Local<Value> line0 = grid->Get(0);
    if (line0->IsArray()) height = Local<Array>::Cast(line0)->Length();

    char _grid[width*height];
    memset (_grid, 0, sizeof (char) * width * height);

    for (int x = 0, size = grid->Length(); x < size; x++) {

	Local<Value> element = grid->Get(x);
	if (element->IsArray()) {
	    Local<Array> gline = Local<Array>::Cast(element);
	    for (int y = 0, ysize = gline->Length(); y<ysize;y++){
		int v = gline->Get(y)->Int32Value();

		_grid[width*y+x] = (v == 0) ? 1 : 0;
	    }
	    // do useful stuff with b
	}
    }
    int solLen = 0;
    int begin = astar_getIndexByWidth (width, startX, startY);
    int end = astar_getIndexByWidth (width, goalX, goalY);
    int *solution = astar_compute (_grid, &solLen, width, height, begin, end);

    Local<Array> result = Array::New(isolate, solLen);
    //auto result = Array::New(solLen);
    int idx = 0;
    for (int i=solLen; i>=0; i--)
    {
	int x = 0;
	int y = 0;
	astar_getCoordByWidth(width, solution[i], &x, &y);
	//printf(" > %d\n",solution[i]);
	//printf(" > %d,%d\n",x, y);

	Local<Array> item = Array::New(isolate, 2);
	item->Set(0, Number::New(isolate, x));
	item->Set(1, Number::New(isolate, y));
	result->Set(idx++, item);
    }



    args.GetReturnValue().Set(result);

}

void Init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "AStarJPS", AStarJPS);
}

NODE_MODULE(pathfinder, Init)
