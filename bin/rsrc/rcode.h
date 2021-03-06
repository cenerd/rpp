namespace rcode
{
	int gbk_to_utf8_c(char* src,char* dst)
	{
		sub esp,4
		push dst
		push src
		calle rf.c_gbk_to_utf8
		mov s_ret,[esp]
		add esp,4
	}

	int gbk_to_utf16_c(char* src,char* dst)
	{
		sub esp,4
		push dst
		push src
		calle rf.c_gbk_to_utf16
		mov s_ret,[esp]
		add esp,4
	}

	int utf8_to_gbk_c(char* src,char* dst)
	{
		sub esp,4
		push dst
		push src
		calle rf.c_utf8_to_gbk
		mov s_ret,[esp]
		add esp,4
	}

	int utf8_to_utf16_c(char* src,char* dst)
	{
		sub esp,4
		push dst
		push src
		calle rf.c_utf8_to_utf16
		mov s_ret,[esp]
		add esp,4
	}

	int utf16_to_gbk_c(char* src,char* dst)
	{
		sub esp,4
		push dst
		push src
		calle rf.c_utf16_to_gbk
		mov s_ret,[esp]
		add esp,4
	}

	int utf16_to_utf8_c(char* src,char* dst)
	{
		sub esp,4
		push dst
		push src
		calle rf.c_utf16_to_utf8
		mov s_ret,[esp]
		add esp,4
	}

	rstr gbk_to_utf8(rstr s)
	{
		rstr ret
		ret.set_size gbk_to_utf8_c(s.cstr,null)
		gbk_to_utf8_c(s.begin,ret.begin)
		ret.pop
		return ret
	}

	rstr gbk_to_utf16(rstr s)
	{
		rstr ret
		ret.set_size gbk_to_utf16_c(s.cstr,null)
		gbk_to_utf16_c(s.begin,ret.begin)
		ret.pop
		ret.pop
		return ret
	}

	rstr utf8_to_gbk(rstr s)
	{
		rstr ret
		ret.set_size utf8_to_gbk_c(s.cstr,null)
		utf8_to_gbk_c(s.begin,ret.begin)
		ret.pop
		return ret
	}

	rstr utf8_to_utf16(rstr s)
	{
		rstr ret
		ret.set_size utf8_to_utf16_c(s.cstr,null)
		utf8_to_utf16_c(s.begin,ret.begin)
		ret.pop
		ret.pop
		return ret
	}

	rstr utf16_to_gbk(rstr s)
	{
		char ch=0
		s.push(ch)
		s.push(ch)
		rstr ret
		ret.set_size utf16_to_gbk_c(s.begin,null)
		utf16_to_gbk_c(s.begin,ret.begin)
		ret.pop
		return ret
	}

	rstr utf16_to_utf8(rstr s)
	{
		char ch=0
		s.push(ch)
		s.push(ch)
		rstr ret
		ret.set_size utf16_to_utf8_c(s.begin,null)
		utf16_to_utf8_c(s.begin,ret.begin)
		ret.pop
		return ret
	}

	//是否utf8 3个字节起始
	static rbool is_utf8_3(char ch)
	{
		return int(ch)>=0xe0&&int(ch)<=0xef;
	}

	static rbool is_utf8_2(char ch)
	{
		return int(ch)>=0xc0&&int(ch)<=0xdf;
	}
}