#pragma once

class Shapes
{
public:
	enum class ShapeSize
	{
		SMALL,
		MEDIUM,
		LARGE
	};

public:
	ShapeSize size = ShapeSize::MEDIUM;

	Shapes();
};
