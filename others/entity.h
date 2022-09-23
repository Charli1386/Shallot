#pragma once

class Entity{
	public:
		static int a;
	protected:
		int x, y;
	public:
		Entity();
		Entity(int x, int y);
		int getX() const;
		int getY() const;
		~Entity();
};
