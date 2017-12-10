#pragma once

namespace Colors {
	class RGB
	{
	public:
		RGB() {};
		RGB(int r, int g, int b, int a);
		virtual ~RGB();
		int getR() { return r; }
		int getB() { return b; }
		int getG() { return g; }
		int getA() { return a; }
		int toColorValue();

	protected:

	private:
		int r, g, b, a;
	};

	static RGB RED(255, 0, 0, 1);
	static RGB GREEN(0, 255, 0, 1);
	static RGB BLUE(0, 0, 255, 1);
	static RGB WHITE(255, 255, 255, 1);
}

