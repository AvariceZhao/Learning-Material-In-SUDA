#pragma once
template<typename Entry>
class SequenceList 
{
protected:
	static const int maxSize = 500;
	int size = 0;
	Entry data[maxSize];
public:
	SequenceList() { size = 0; }
	SequenceList(Entry array[], int len);
	SequenceList(const SequenceList<Entry>& list);
	~SequenceList();
	Entry& Get(int index);
	int Find(const Entry& element);
	void Insert(int index, const Entry& element);
	Entry Delete(int pos);
	bool Empty();
	int Length();
	void Clear();
	void Print();
	static const int notFound;
	
};
template<typename Entry>
const int SequenceList<Entry>::notFound = 0;


template<typename Entry>
SequenceList<Entry>::SequenceList(Entry array[], int len)
{
	if (len > maxSize || len <= 0)
	{
		throw std::invalid_argument{ "Invalid len" };
	}
	for (int i = 0; i < len; i++)
	{
		data[i] = array[i];
	}
	size = len;
}
template<typename Entry>
SequenceList<Entry>::SequenceList(const SequenceList<Entry>& list)
{
	for (int i = 0; i < list.size; i++)
	{
		data[i] = list.data[i];
	}
	size = list.size;
}
template<typename Entry>
SequenceList<Entry>::~SequenceList()
{

}
template<typename Entry>
Entry& SequenceList<Entry>::Get(int index)
{
	if (index<1 || index>size)	throw std::out_of_range{ "invalid index" };
	return data[index - 1];

}
template<typename Entry>
int SequenceList<Entry>::Find(const Entry& element)
{
	for (int i = 0; i < size; i++)
		if (data[i] == element)
		{
			return i + 1;
		}
	return notFound;
}
template<typename Entry>
Entry SequenceList<Entry>::Delete(int index)
{
	if (size == 0)throw std::underflow_error{ "The list has been empty" };
	if (index <= 0 || index > size)throw std::out_of_range{ "Invalid index is given" };
	Entry element = data[index - 1];
	for (int i = index; i < size; i++)data[i - 1] = data[i];
	size--;
	return element;
}

template<typename Entry>
bool SequenceList<Entry>::Empty()
{
	return size == 0;
}
template<typename Entry>
int SequenceList<Entry>::Length()
{
	return size;
}
template<typename Entry>
void SequenceList<Entry>::Clear()
{
	size = 0;
}
template<typename Entry>
void SequenceList<Entry>::Print()
{
	for (int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
	
}
template<typename Entry>
void SequenceList<Entry>::Insert(int index, const Entry& element)
{
	if (size >= maxSize) {
		throw std::overflow_error{ "The length of this list has been the maximum" };
	}
	if (index < 1 || index > size + 1) {
		throw std::out_of_range{ "The argument 'index' is out of range" };
	}
	for (int i = size; i >= index; --i) {
		data[i] = data[i - 1];
	}
	data[index - 1] = element;
	++size;
}