#pragma once
namespace GlutConfigFunc {
	class Display
	{
	public:
		static void display() {}
	};

	class Reshape
	{
	public:
		virtual void reshape() = 0;
	};

	class Keyboard {
	public:
		virtual void keyboard() = 0;
	};

}