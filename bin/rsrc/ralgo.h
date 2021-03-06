
void r_swap<T>(T& a,T& b)
{
	temp=a
	a=b
	b=temp
}

void r_reverse<T>(rbuf<T>& v,int begin,int end=v.count)
{
	end--
	for begin<end
		r_swap<T>(v[begin],v[end])
		begin++
		end--
}

int r_find_pos<V>(const V& v,const V& m,int start=0)
{
	if (m.empty()||start>=v.count())
	{
		return v.count();
	}
	for (int i=start;i<v.count()-m.count()+1;i++)
	{
		if (v[i]!=m[0])
		{
			continue;
		}
		int j;
		for (j=0;j<m.count();j++)
		{
			if (v[i+j]!=m[j])
			{
				break;
			}
		}
		if (j>=m.count())
		{
			return i;
		}
	}
	return v.count();
}

void r_split<V>(const V& v,const V& m,rbuf<V>& result,int start=0)
{
	result.clear();
	V temp;
	int i;
	while(start<v.count())
	{
		int pos=r_find_pos<V>(v,m,start);
		if(pos>=v.count())
			break;
		temp.clear();
		for(i=start;i<pos;i++)
			temp+=v[i];
		if(!temp.empty())
			result.push(temp);
		start=pos+m.count();
	}
	temp.clear();
	for(i=start;i<v.count();i++)
		temp+=v[i];
	if(!temp.empty())
		result.push(temp);
}

rbuf<V> r_split_r<V>(V& v,V& m)
{
	rbuf<V> ret
	r_split<V>(v,m,ret)
	return ret
}

//允许空元素
void r_split_e<V>(const V& v,const V& m,rbuf<V>& result,int start=0)
{
	result.clear();
	V temp;
	int i;
	while(start<v.count())
	{
		int pos=r_find_pos<V>(v,m,start);
		if(pos>=v.count())
			break;
		temp.clear();
		for(i=start;i<pos;i++)
			temp+=v[i];
		result.push(temp);
		start=pos+m.count();
	}
	temp.clear();
	for(i=start;i<v.count();i++)
		temp+=v[i];
	result.push(temp);
}

rbuf<V> r_split_e_r<V>(V& v,V& m)
{
	rbuf<V> ret
	r_split_e<V>(v,m,ret)
	return ret
}

void r_qsort_in<T>(rbuf<T>& v,int left,int right)
{
	if(left<right)
	{
		T pivot=v[right];
		int i=left;
		for(int j=left;j<right;j++)
		{
			if(v[j]<=pivot)
			{
				r_swap<T>(v[i],v[j]);
				i++;
			}
		}
		r_swap<T>(v[i],v[right]);
		r_qsort_in<T>(v,left,i-1);
		r_qsort_in<T>(v,i+1,right);
	}
}

//快排
void r_qsort<T>(rbuf<T>& v,int begin=0,int end=0)
{
	if(end<=0)
	{
		end=v.count();
	}
	if(begin<0)
	{
		begin=0;
	}
	if(begin+1<end)
		r_qsort_in<T>(v,begin,end-1);
}

//二分
int r_find_pos_b<T>(const rbuf<T>& v,T a)
{
	int left=0;
	int right=v.count()-1;
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(v[mid]<a)
			left=mid+1;
		elif(a<v[mid])
			right=mid-1;
		else
			return mid;
	}
	return v.count();
}