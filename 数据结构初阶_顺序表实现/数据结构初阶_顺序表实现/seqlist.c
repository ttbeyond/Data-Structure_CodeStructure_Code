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
//��������Ƿ��㹻����������������
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
	//���ٵ���һ��Ԫ�أ����ܽ��д˲���
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
	printf("����û�д�Ԫ��\n");
}
int SeqListSize(SeqList* ps) //��Ч����
{
	assert(ps);
	return ps->_size;
}
SLDataType SeqListAt(SeqList* ps, size_t post)//��ѯpostλ�ô�������
{
	assert(ps);
	return ps->_array[post];
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//����λ�ò���ֵΪx�Ľڵ�
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
void SeqListErase(SeqList* ps, size_t pos)//����λ��ɾ��
{
	assert(ps&&ps->_size > pos);

	size_t start = pos+1;//�ҳ�posλ�õ���һ��λ��
	while (start < ps->_size)
	{
		ps->_array[start - 1] = ps->_array[ start ];
		++start;
	}
	ps->_size--;
}

void SeqListRemove(SeqList* ps, SLDataType x)  //�Ƴ�ֵΪx�ĵ�һ���ڵ�
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
	printf("˳������޴�Ԫ��\n");
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)//��posλ�õ�ֵ��Ϊx
{
	assert(ps&&ps->_size > pos);
	
	ps->_array[pos] = x;
}

void SeqListBubbleSort(SeqList* ps)//��˳������ð������
{
	assert(ps);
	
		for (size_t i = 0; i<ps->_size-1 ; i--)
		{
			int flag = 0;
			for (size_t j = 0; j < ps->_size -i-1; ++j)//����
			{
				if (ps->_array[j]>ps->_array[j + 1])
				{
					SLDataType ret = ps->_array[j];
					ps->_array[j] = ps->_array[j + 1];
					ps->_array[j + 1] = ret;
					flag = 1;
				}
			}
			if (flag == 0)//˳���������������м��κ���������(����)
				break;
		}
	
}
int SeqListBinaryFind(SeqList* ps, SLDataType x)//��һ������˳�����ж��ֲ���
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
	printf("˳������޴�Ԫ��\n");
}
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)//ɾ��˳���������ֵΪx�Ľڵ�
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