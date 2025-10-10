#include "Input.hpp"

Input Input::instance;

Input& Input::Get()
{
	return instance;
}

Input::Input()
{

}