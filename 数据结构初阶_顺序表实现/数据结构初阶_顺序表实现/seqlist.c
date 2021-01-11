#include"seqlist.h";

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_size = 0;
	ps->_array = NULL;
	free(ps->_array );
}
//检查容量是否足够，不够按二倍扩容
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (SLDataType*)realloc(ps->_array, sizeof(SLDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);

	ps->_array[ps->_size] = x;
	ps->_size++;

}
void SeqListPopBack(SeqList* ps)
{
	assert(ps&&ps->_size >0);
	//至少得有一个元素，才能进行此操作
	ps->_size--;
}
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps); 

	size_t end = ps->_size;
	while (end>0)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[0] = x;
	ps->_size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps&&ps->_size > 0);
	size_t start = 0;
	while (start<ps->_size -1)
	{
		ps->_array[start] = ps->_array[start+1];
		++start;
	}
	ps->_size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	size_t start = 0;
	for (start; start < ps->_size; start++)
	{
		if (ps->_array[start] == x)
			return x;
	}
	printf("表中没有此元素\n");
}
int SeqListSize(SeqList* ps) //有效个数
{
	assert(ps);
	return ps->_size;
}
SLDataType SeqListAt(SeqList* ps, size_t post)//查询post位置处的数据
{
	assert(ps);
	return ps->_array[post];
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//任意位置插入值为x的节点
{
	assert(ps&&ps->_size >=pos);
	CheckCapacity(ps);

	size_t end = ps->_size;
	while (end >pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqListErase(SeqList* ps, size_t pos)//任意位置删除
{
	assert(ps&&ps->_size > pos);

	size_t start = pos+1;//找出pos位置的下一个位置
	while (start < ps->_size)
	{
		ps->_array[start - 1] = ps->_array[ start ];
		++start;
	}
	ps->_size--;
}

void SeqListRemove(SeqList* ps, SLDataType x)  //移除值为x的第一个节点
{
	assert(ps);

	size_t start = 0;
	for (start; start < ps->_size; ++start)
	{
		if (ps->_array[start] == x)
		{
          SeqListErase(ps, start);
		  return;
		}		
	}
	printf("顺序表中无此元素\n");
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)//将pos位置的值改为x
{
	assert(ps&&ps->_size > pos);
	
	ps->_array[pos] = x;
}

void SeqListBubbleSort(SeqList* ps)//对顺序表进行冒泡排序
{
	assert(ps);
	
		for (size_t i = 0; i<ps->_size-1 ; i--)
		{
			int flag = 0;
			for (size_t j = 0; j < ps->_size -i-1; ++j)//单趟
			{
				if (ps->_array[j]>ps->_array[j + 1])
				{
					SLDataType ret = ps->_array[j];
					ps->_array[j] = ps->_array[j + 1];
					ps->_array[j + 1] = ret;
					flag = 1;
				}
			}
			if (flag == 0)//顺序表本身有序或者排列几次后有序的情况(升序)
				break;
		}
	
}
int SeqListBinaryFind(SeqList* ps, SLDataType x)//对一个有序顺序表进行二分查找
{
	assert(ps);
	int left = 0;
	int right = ps->_size - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (ps->_array[mid] < x)
		{
			left = mid + 1;
		}
		else if (ps->_array[mid]>x)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	printf("顺序表中无此元素\n");
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)//删除顺序表中所有值为x的节点
{
	assert(ps);
	size_t index = 0;
	for (int i = 0; i < SeqListSize(ps); i++)
	{
		if (ps->_array[index] != x)
		{
			ps->_array[index] = ps->_array[i];
			++index;
		}
	}
	ps->_size = index;
	return ps;
}