#pragma once

namespace Colors {
	class RGB
	{
	public:
		RGB() {};
		RGB(float r, float g, float b, float a);
		//RGB(Colors::RGB color);
		virtual ~RGB();
		float getR() { return r; }
		float getB() { return b; }
		float getG() { return g; }
		float getA() { return a; }
		float toColorValue();
		float* toVector() {
			float tmp[] = { r,g,b };
			return tmp;
		}
	protected:

	private:
		float r, g, b, a;
	};

	static RGB RED(1.0f, 0.0f, 0.0f, 1);
	static RGB GREEN(0.0f, 1.0f, 0.0f, 1);
	static RGB BLUE(0.0f, 0.0f, 1.0f, 1);
	static RGB BROWN(0.5f, 0.35f, 0.05f, 1);

	static RGB MAGENTA(1.0f, 0.0f, 1.0f, 1);
	static RGB ORANGE(1.0f, 0.5f, 0.0f, 1);
	static RGB YELLOW(1.0f, 1.0f, 0.0f, 1);

	static RGB GRAY(0.5f, 0.5f, 0.5f, 1);
	static RGB WHITE(1.0f, 1.0f, 1.0f, 1);
	static RGB BLACK(0.0f, 0.0f, 0.0f, 1);

	 static RGB DARKWHITE(0.95f, 0.95f, 0.95f, 1);
	static RGB DARKGRAY(0.2f, 0.2f, 0.2f, 1);

	static RGB LIGHTBROWN(0.95f, 0.8f, 0.7f, 1);
	static RGB DARKBROWN(0.3f, 0.15f, 0.15f, 1);

	static RGB LIGHTBLUE (0.0, 0.6, 0.9, 1.0);

}

