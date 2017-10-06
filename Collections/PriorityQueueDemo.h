#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <boost/optional.hpp>

class PriorityQueueDemo
{

public:
	class less : public Comparator<int>
	{
	private:
		PriorityQueueDemo *outerInstance;

	public:
		less(PriorityQueueDemo *outerInstance);

		virtual int compare(boost::optional<int> a, boost::optional<int> b);
	};

public:
	class more : public Comparator<int>
	{
	private:
		PriorityQueueDemo *outerInstance;

	public:
		more(PriorityQueueDemo *outerInstance);

		virtual int compare(boost::optional<int> a, boost::optional<int> b);
	};

	static void main(std::vector<std::wstring> &args);
};
