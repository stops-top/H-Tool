//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitLuaApi.h"
#include "UnitMain.h"
#include "bsp.h"
#include "bsp_udp_modbus.h"
#include "bsp_user_lib.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLuaApi *FormLuaApi;
//---------------------------------------------------------------------------
__fastcall TFormLuaApi::TFormLuaApi(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//添加源码, 非最终行
void __fastcall TFormLuaApi::AddLuaSrc0(AnsiString str)
{
	Memo1->Lines->Add(str);
	MemoTemp->Lines->Add(str);
}

//---------------------------------------------------------------------------
//添加源码, 最终行
void __fastcall TFormLuaApi::AddLuaSrc(AnsiString str)
{
	Memo1->Lines->Add(str);

	MemoTemp->Lines->Add(str);
	// 自动复制到剪切板
	MemoTemp->SelectAll();
	MemoTemp->CopyToClipboard();
	MemoTemp->Clear();
}

//---------------------------------------------------------------------------
//添加帮助到MemoOut
void __fastcall TFormLuaApi::AddLuaToMemo(AnsiString str)
{
	Form1->MemoLuaOut->Lines->Add(str);
}

void __fastcall TFormLuaApi::Button3Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc0("--启动模拟量电路");
	AddLuaSrc0("function start_dso(void)");
	AddLuaSrc0("  write_reg16(0x01FF, 2) -- 测量模式 0:示波器 1:负载电流 2:多路低速扫描");
	AddLuaSrc0("  write_reg16(0x0200, 1) -- CH1耦合,0:AC 1:DC");
	AddLuaSrc0("  write_reg16(0x0201, 1) -- CH2耦合,0:AC 1:DC");
	AddLuaSrc0("  --量程取值 0:±13.8V 1:±6.4V 2:±3.2V 3:±1.6V 4:±800mV 5:±400mV 6:±200mV 7:±100mV");
	AddLuaSrc0("  write_reg16(0x0202, 0) -- CH1量程");
	AddLuaSrc0("  write_reg16(0x0203, 0) -- CH2量程");
	AddLuaSrc0("  write_reg16(0x0204, 0) -- CH1通道直流偏值，未用");
	AddLuaSrc0("  write_reg16(0x0205, 0) -- CH2通道直流偏值，未用");
	AddLuaSrc0("  write_reg16(0x0206, 12) --采样频率 0:100 1:200 2:500 3:1K 4:2K 5:5K 6:10K 7:20K");
	AddLuaSrc0("                          --8:50K 9:100K 10:200K 11:500K 12:1M 13:2M 14:5M");
	AddLuaSrc0("  write_reg16(0x0207, 0) --采样深度 0:1K 1:2K 3:4K 4:8K 5:16K 6:32K");
	AddLuaSrc0("  write_reg16(0x0208, 32768) --触发电平ADC 0-65535");
	AddLuaSrc0("  write_reg16(0x0209, 50) --触发位置百分比 0-100");
	AddLuaSrc0("  write_reg16(0x020A, 0) --触发模式 0:自动 1:普通 2:单次");
	AddLuaSrc0("  write_reg16(0x020B, 0) --触发通道 0:CH1 1:CH2");
	AddLuaSrc0("  write_reg16(0x020C, 0) --触发边沿 0:下降沿 1:上升沿 ");
	AddLuaSrc0("  write_reg16(0x020D, 0x03) --通道使能控制 bit0 = CH1  bit1 = CH2");
	AddLuaSrc0("  write_reg16(0x020E, 1) --采集控制 0:停止 1:启动");
	AddLuaSrc("end");

}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::ButtonReadAdcClick(TObject *Sender)
{
	int ch;
	AnsiString str;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}
	const char *AnCh[9] = {
		"0 - CH1电压",
		"1 - CH2电压",
		"2 - 高侧负载电压",
		"3 - 高端负载电流",
		"4 - TVCC电压",
		"5 - TVCC电流",
		"6 - NTC热敏电阻阻值",
		"7 - 外部供电电压",
		"8 - USB供电电压",
	};


	ch = ComboBoxAiCh->ItemIndex;
	str = AnCh[ch];
	AddLuaSrc("read_adc(" + IntToStr(ch)+ ") --" + str);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button1Click(TObject *Sender)
{
	int ch;
	AnsiString str;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}
	const char *AnCh[9] = {
		"0 - CH1电压",
		"1 - CH2电压",
		"2 - 高侧负载电压",
		"3 - 高端负载电流",
		"4 - TVCC电压",
		"5 - TVCC电流",
		"6 - NTC热敏电阻阻值",
		"7 - 外部供电电压",
		"8 - USB供电电压",
	};


	ch = ComboBoxAiCh->ItemIndex;
	str = AnCh[ch];
	AddLuaSrc("read_analog(" + IntToStr(ch)+ ") --" + str);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button2Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}
	AddLuaSrc("dac_on() --开启DAC电源");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button4Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}
	AddLuaSrc("dac_off() --关闭DAC电源");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button5Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc("dac_volt(" + EditMV->Text + ") --设置DAC输出电压mV");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button6Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc("dac_curr(" + EditUA->Text + ") --设置DAC输出电流uA");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button7Click(TObject *Sender)
{
	AnsiString src;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	src = "set_tvcc(" + EditTVCC->Text + ") --设置TVCC输出电压0或1.2-5.5V";
	AddLuaSrc(src);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button8Click(TObject *Sender)
{
	AnsiString src;
	int pin;
	int mode;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	pin = ComboBoxGpioId->ItemIndex;
	mode =  ComboBoxGpioMode->ItemIndex;

	src = "gpio_cfg(" + IntToStr(pin) + ", " + IntToStr(mode) + ") --配置模式"
		+ ComboBoxGpioId->Text + " = " + ComboBoxGpioMode->Text;
	AddLuaSrc(src);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button9Click(TObject *Sender)
{
	AnsiString src;
	int pin;
	int mode;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	pin = ComboBoxGpioId->ItemIndex;
	mode =  ComboBoxGpioMode->ItemIndex;

	src = "gpio_write(" + IntToStr(pin) + ", " + "1) --设置输出"
		+ ComboBoxGpioId->Text + " = 1";
	AddLuaSrc(src);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button10Click(TObject *Sender)
{
	AnsiString src;
	int pin;
	int mode;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	pin = ComboBoxGpioId->ItemIndex;
	mode =  ComboBoxGpioMode->ItemIndex;

	src = "gpio_write(" + IntToStr(pin) + ", " + "0) --设置输出"
		+ ComboBoxGpioId->Text + " = 0";
	AddLuaSrc(src);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button11Click(TObject *Sender)
{
	AnsiString src;
	int pin;
	int mode;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	pin = ComboBoxGpioId->ItemIndex;
	mode =  ComboBoxGpioMode->ItemIndex;

	src = "pin = gpio_read(" + IntToStr(pin) + ") --读GPIO状态";
	AddLuaSrc(src);
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button12Click(TObject *Sender)
{
	AnsiString src;
	int pin;
	int mode;

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	pin = ComboBoxGpioId->ItemIndex;
	mode =  ComboBoxGpioMode->ItemIndex;

	src = "pa = read_bus() --整体读全部的GPIO状态";
	AddLuaSrc(src);
}
//---------------------------------------------------------------------------


void __fastcall TFormLuaApi::ComboBoxStringFuncClick(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	//	string.byte 字符转换成ascii数字
	//	string.char Ascii数值转换成字符
	//	string.sub 截取字符串
	//	string.find 字符串查找函数
	//	string.match 字符串查找函数
	//	string.gsub 字符串替换
	//	string.format 字符串格式化类型
	//	string.len 返回字符串长度=#s
	//	string.rep 字符串重复n次并拼接返回
	//	string.lower 转小写
	//	string.upper 转大写
	//	string.reverse 反转字符串

	if (ComboBoxStringFunc->ItemIndex == 0)
	{
		//	string.byte 字符转换成ascii数字
		AddLuaSrc0("string.byte(s [, i [, j]])");
		AddLuaSrc0("");
		AddLuaSrc0("string.byte是用来把字符转换成ascii数字，");
		AddLuaSrc0("s为目标字符串，i为索引开始位置(从1开始)，j为索引结束位置");
		AddLuaSrc0("例子");
		AddLuaSrc0("--默认为第1个返回a的ascii值");
		AddLuaSrc0("local r = string.byte('abcdefg') --97");

		AddLuaSrc0("--从索引2(b)到索引4(d)也就是分别返回bcd的ascii值");
		AddLuaSrc0("local r1,r2,r3 = string.byte('abcdefg',2,4) --98,99,100");
	}
	else if (ComboBoxStringFunc->ItemIndex == 1)
	{
		//	string.char Ascii数值转换成字符
		AddLuaSrc0("string.char(...)");
		AddLuaSrc0("");
		AddLuaSrc0("string.char是把ascii数值转换成字符");
		AddLuaSrc0("例子");
		AddLuaSrc0("--返回98所对应的字符");
		AddLuaSrc0("local r = string.char(98) --a");

		AddLuaSrc0("--返回98,,99,100对应的字符并连在一起返回");
		AddLuaSrc0("local r = string.char(98,99,100) --abc");
	}
	else if (ComboBoxStringFunc->ItemIndex == 2)
	{
		AddLuaSrc0("string.sub (s, i [, j])");
		AddLuaSrc0("");
		AddLuaSrc0("截取字符串(字符串分割，字符串截取)，i为起始索引，可选参数j为结束索引(包含)，都可以为负数，第一个字符索引为1，最后一个字符为-1");
		AddLuaSrc0("例子");
		AddLuaSrc0("local res,s");
		AddLuaSrc0("s = 'www.armfly.com'");
		AddLuaSrc0("res = string.sub(s,5)     --armfly.com");
		AddLuaSrc0("res = string.sub(s,5,-1)  --armfly.com");
		AddLuaSrc0("");
		AddLuaSrc0("--截取后3位");
		AddLuaSrc0("res = string.sub(s,-3)    --com");
		AddLuaSrc0("");
		AddLuaSrc0("--截取前3位");
		AddLuaSrc0("res = string.sub(s,1,3)   --www");
	}
	else if (ComboBoxStringFunc->ItemIndex == 3)
	{
	//	string.find 字符串查找函数
		AddLuaSrc0("string.find (s, pattern [, init [, plain]])");
		AddLuaSrc0("");
		AddLuaSrc0("字符串查找函数找不到返回nil，找到了返回开始位置和结束位置，");
		AddLuaSrc0("init为从哪里开始默认为1，plain默认为false表示利用模式匹配，");
		AddLuaSrc0("如果设为true则表示纯文本匹配(也就是关闭正则匹配)");
		AddLuaSrc0("例子");
		AddLuaSrc0("local str = 'i love programming,11,22,%d+aa'");
		AddLuaSrc0("local s = string.find(str,'222')    --nil");
		AddLuaSrc0("s = string.find(str,'pro')  --8");
		AddLuaSrc0("s = string.find(str,\",%d+\")    --19(匹配到了,11)");
		AddLuaSrc0("s = string.find(str,\",%d+\",1,true) --25(由于关闭了模式匹配,所以匹配到了,%d+)");
	}
	else if (ComboBoxStringFunc->ItemIndex == 4)
	{
	//	string.match 字符串查找函数
		AddLuaSrc0("string.match (s, pattern [, init])");
		AddLuaSrc0("");
		AddLuaSrc0("它跟string.find差不多，只不过能把捕获匹配到的结果并返回");
		AddLuaSrc0("例子");
		AddLuaSrc0("local s,res,res1,res2");
		AddLuaSrc0("s = 'http://www.armfly.com'");
		AddLuaSrc0("");
		AddLuaSrc0("--由于没有捕获，返回全部匹配");
		AddLuaSrc0("--结果：http://www.armfly.com");
		AddLuaSrc0("res = string.match(s,'http://%a+\.%a+\.com')");
		AddLuaSrc0("");
		AddLuaSrc0("--如果有捕获，则分别返回捕获结果");
		AddLuaSrc0("--结果：www    armfly");
		AddLuaSrc0("res1,res2 = string.match(s,'http://(%a+)\.(%a+)\.com')");
	}
	else if (ComboBoxStringFunc->ItemIndex == 5)
	{
	//	string.gsub 字符串替换
		AddLuaSrc0("string.gsub (s, pattern, repl [, n])");
		AddLuaSrc0("");
		AddLuaSrc0("用来做字符串替换，可选参数n代表替换多少次默认全部替换，");
		AddLuaSrc0("返回替换后的字符串，也可以指定第二个返回值为替换的次数。");
		AddLuaSrc0("例子");
		AddLuaSrc0("local s,res,res1,res2");
		AddLuaSrc0("s = 'http://www.armfly.com'");
		AddLuaSrc0("");
		AddLuaSrc0("--结果：http://test.armfly.com，1");
		AddLuaSrc0("res,count = string.gsub(s,'www','test')");
		AddLuaSrc0("");
		AddLuaSrc0("--捕获替换");
		AddLuaSrc0("--结果：test.freecls.abc");
		AddLuaSrc0("res = string.gsub(s,'^http://%w+\.(%w+)\.com$','test.%1.abc')");
		AddLuaSrc0("");
		AddLuaSrc0("--w替换成t，但是只替换2次");
		AddLuaSrc0("--结果：http://ttw.armfly.com");
		AddLuaSrc0("res = string.gsub(s,'w','t',2)");

	}
	else if (ComboBoxStringFunc->ItemIndex == 6)
	{
	//	string.format 字符串格式化类型
		AddLuaSrc0("string.format (formatstring, ···)");
		AddLuaSrc0("字符串格式化类型c语言的sprintf不说废话以例子来讲解");
		AddLuaSrc0("");
		AddLuaSrc0("local s = string.format('%d%s',123,'armfly')   --123armlfy");
		AddLuaSrc0("");
		AddLuaSrc0("s = string.format('%0.2f',1.234343)     --1.23(保留2位)");
		AddLuaSrc0("");
		AddLuaSrc0("--转成16进制，%X为大写的16进制");
		AddLuaSrc0("local s = string.format('%X',140)       --8C");
		AddLuaSrc0("local s = string.format('%x',140)       --8c");
		AddLuaSrc0("local s = string.format('%04x',140)     --008c");
	}
	else if (ComboBoxStringFunc->ItemIndex == 7)
	{
	//	string.len 返回字符串长度=#s
		AddLuaSrc0("string.len(s)");
		AddLuaSrc0("");
		AddLuaSrc0("返回字符串长度=#s");
	}
	else if (ComboBoxStringFunc->ItemIndex == 8)
	{
	//	string.rep 字符串重复n次并拼接返回
		AddLuaSrc0("string.rep(s,n)");
		AddLuaSrc0("");
		AddLuaSrc0("字符串重复n次并拼接返回");
	}
	else if (ComboBoxStringFunc->ItemIndex == 9)
	{
	//	string.lower 转小写
		AddLuaSrc0("string.lower(s)");
		AddLuaSrc0("");
		AddLuaSrc0("转小写");
	}
	else if (ComboBoxStringFunc->ItemIndex == 10)
	{
	//	string.upper 转大写
		AddLuaSrc0("string.upper(s)");
		AddLuaSrc0("");
		AddLuaSrc0("转大写");
	}
	else if (ComboBoxStringFunc->ItemIndex == 11)
	{
	//	string.reverse 反转字符串
		AddLuaSrc0("string.reverse(s)");
		AddLuaSrc0("");
		AddLuaSrc0("反转字符串");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button13Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc0("变量");
	AddLuaSrc0("1.变量无需声明");
	AddLuaSrc0("2.变量没声明为nil,赋值为nil等同于删除");
	AddLuaSrc0("3.lua把nil,false视为假,其他都为true");
	AddLuaSrc0("4.Lua中的变量全是全局变量,除非用 local 显式声明为局部变量");
	AddLuaSrc0("5.#ta字符串的长度，也可以获取表格数字索引对应的个数");
	AddLuaSrc0("");
	AddLuaSrc0("例子");
	AddLuaSrc0("--全局赋值");
	AddLuaSrc0("x = 1");
	AddLuaSrc0("");
	AddLuaSrc0("--局部多个赋值");
	AddLuaSrc0("local x,y = 1,2");
	AddLuaSrc0("");
	AddLuaSrc0("local ta = {1,2,3,name='安富莱'}");

	AddLuaSrc0("--3");
	AddLuaSrc0("print(#ta)");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button14Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc0("注释、多行注释、取消多行注释");
	AddLuaSrc0("例子");
	AddLuaSrc0("注释单行");
	AddLuaSrc0("--local a = 1");
	AddLuaSrc0("");
	AddLuaSrc0("注释多行");
	AddLuaSrc0("--[[");
	AddLuaSrc0("local a = 1");
	AddLuaSrc0("--]]");

	AddLuaSrc0("取消注释多行");
	AddLuaSrc0("---[[");
	AddLuaSrc0("local a = 1");
	AddLuaSrc0("--]]");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button15Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc0("条件");
	AddLuaSrc0("if");
	AddLuaSrc0("and or not");
	AddLuaSrc0(">= <= == > < ~=");
	AddLuaSrc0("");
	AddLuaSrc0("例子");
	AddLuaSrc0("if (a >= 0) then   --大于等于");
	AddLuaSrc0("  b = b + 1");
	AddLuaSrc0("else");
	AddLuaSrc0("  b = b - 1");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("if (a ~= 0) then   --不等于");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("if (a==b and c == 0) then --逻辑与");
	AddLuaSrc0("");
	AddLuaSrc0("elseif (a~=b) then  --不等于");
	AddLuaSrc0("");
	AddLuaSrc0("elseif (not a) then  --逻辑非");
	AddLuaSrc0("");
	AddLuaSrc0("else");
	AddLuaSrc0("");
	AddLuaSrc0("end");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button16Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc0("循环");
	AddLuaSrc0("例子");
	AddLuaSrc0("local a=10");
	AddLuaSrc0("while (a < 20)");
	AddLuaSrc0("do");
	AddLuaSrc0("   a = a + 1");
	AddLuaSrc0("   print(a)");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("local t = {1,2,3}");
	AddLuaSrc0("for i,v in pairs(t) do");
	AddLuaSrc0("    print(v)");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("--每次加1");
	AddLuaSrc0("for i=0,5,1 do");
	AddLuaSrc0("    print(i)");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("--每次减1");
	AddLuaSrc0("--5,4,3,2,1");
	AddLuaSrc0("for i=5,1,-1 do");
	AddLuaSrc0("    print(i)");
	AddLuaSrc0("end");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button17Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	AddLuaSrc0("函数");
	AddLuaSrc0("例子");
	AddLuaSrc0("--声明函数，传递2个参数，返回2个值得和");
	AddLuaSrc0("function add(num1, num2)");
	AddLuaSrc0("   return num1 + num2");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("--把函数赋值给一个变量，然后可以当参数传递");
	AddLuaSrc0("local myprint = function(str)");
	AddLuaSrc0("   print(str)");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("function say(arg1,func)");
	AddLuaSrc0("    func(arg1)");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("--www.freecls.com");
	AddLuaSrc0("say('www.freecls.com',myprint)");
	AddLuaSrc0("");
	AddLuaSrc0("--可变参数");
	AddLuaSrc0("function average(...)");
	AddLuaSrc0("   result = 0");
	AddLuaSrc0("   local arg={...}");
	AddLuaSrc0("   for i,v in ipairs(arg) do");
	AddLuaSrc0("      result = result + v");
	AddLuaSrc0("   end");
	AddLuaSrc0("   print(\"总共传入 \" .. #arg .. \" 个数\")");
	AddLuaSrc0("   return result/#arg");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("function what()");
	AddLuaSrc0("    return '安富莱','www.armlfy.com'\");");
	AddLuaSrc0("end");
	AddLuaSrc0("");
	AddLuaSrc0("--返回多个参数");
	AddLuaSrc0("local name,url = what()");
	AddLuaSrc0("print(name,url)");
}
//---------------------------------------------------------------------------

#define RGB565(R, G, B) (((R >> 3) << 11) | ((G >> 2) << 5) | (B >> 3)) /* 将8位R,G,B转化为 16位RGB565格式 */
void __fastcall TFormLuaApi::Button18Click(TObject *Sender)
{
	if (ColorDialog1->Execute())
	{
		uint32_t color;
		uint8_t R,G,B;

		color = ColorDialog1->Color;

		R = color >> 0;
		G = color >> 8;
		B = color >> 16;
		EditColorRGB->Text = "RGB565(" + IntToStr(R) + ", "+ IntToStr(G) + ", "+ IntToStr(B) + ")";

		color = RGB565(R,G,B);
		EditColorHex->Text = "0x" + IntToHex((int64_t)color, 4);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button19Click(TObject *Sender)
{
	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

	Memo1->Lines->Add("Lua GUI API 函数列表");
	Memo1->Lines->Add("");
	Memo1->Lines->Add("【函数】RGB565(r, g, b)   --将RGB888颜色转换为RGB565");
	Memo1->Lines->Add("  -- bg = RGB565(0xFF, 0, 0) --红色");
	Memo1->Lines->Add("  -- lcd_clr(RGB565(0xFF, 0xFF, 0xFF)) --清屏，白色");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_refresh()  --刷新界面");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_clr(color)  --清屏，color是RG565颜色格式");
	Memo1->Lines->Add("  1、lcd_clr(RGB565(0xFF, 0xFF, 0xFF))");
	Memo1->Lines->Add("  2、lcd_clr(0x1234)");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_disp_str(x, y, str, fontsize, front_color, back_color, width, align)");
	Memo1->Lines->Add("  -- 显示字符串");
	Memo1->Lines->Add("  -- x, y ：显示坐标, 像素单位, 0-239");
	Memo1->Lines->Add("  -- str ：字符串, 支持GBK编码中文");
	Memo1->Lines->Add("  -- fontsize ：字体大小. 12=12点阵，16=16点阵，24=24点阵，32表示32点阵");
	Memo1->Lines->Add("  -- front_color ：字体颜色, 可以用 RGB(0,0,0)");
	Memo1->Lines->Add("  -- back_color ：背景颜色");
	Memo1->Lines->Add("  -- width ：宽度");
	Memo1->Lines->Add("  -- align ：对齐. 0=左对齐, 1=居中, 2=右对齐");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_fill_rect(x, y, h, w, color)");
	Memo1->Lines->Add("  -- 填充矩形窗口");
	Memo1->Lines->Add("  -- x, y ：矩形左上角, 像素单位, 0-239");
	Memo1->Lines->Add("  -- h, w ：矩形高度和宽度, 像素单位, 1-240");
	Memo1->Lines->Add("  -- color ：填充颜色");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_draw_rect(x, y, h, w, color)");
	Memo1->Lines->Add("  -- 绘制矩形边框");
	Memo1->Lines->Add("  -- x, y ：矩形左上角坐标, 像素单位, 0-239");
	Memo1->Lines->Add("  -- h, w ：矩形高度和宽度, 像素单位, 1-240");
	Memo1->Lines->Add("  -- color ：边框颜色");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_draw_circle(x, y, r, color)");
	Memo1->Lines->Add("  -- 绘制圆圈");
	Memo1->Lines->Add("  -- x, y ：圆心坐标, 像素单位, 0-239");
	Memo1->Lines->Add("  -- r ：圆半径, 像素单位");
	Memo1->Lines->Add("  -- color ：边框颜色");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_draw_line(x1, y1, x2, y2, color)");
	Memo1->Lines->Add("  -- 绘制直线");
	Memo1->Lines->Add("  -- x1, y1 ：第1个点坐标, 像素单位, 0-239");
	Memo1->Lines->Add("  -- x2, y2 ：第2个点坐标, 像素单位, 0-239");
	Memo1->Lines->Add("  -- color ：直线颜色");
	Memo1->Lines->Add("");

	Memo1->Lines->Add("【函数】lcd_disp_label(x, y, h, w, color, str, fontzize, front_color, back_color)");
	Memo1->Lines->Add("  --绘制标签(左右上下居中)");
	Memo1->Lines->Add("  -- x, y ：矩形左上角, 像素单位, 0-239");
	Memo1->Lines->Add("  -- h, w ：矩形高度和宽度, 像素单位, 1-240");
	Memo1->Lines->Add("  -- color ：填充颜色");
	Memo1->Lines->Add("  -- str ：字符串");
	Memo1->Lines->Add("  -- fontzize ：字体大小 12 16 24 32");
	Memo1->Lines->Add("  -- front_color ：字体颜色");
	Memo1->Lines->Add("  -- back_color ：字体背景颜色");
	Memo1->Lines->Add("");
}
//---------------------------------------------------------------------------

void __fastcall TFormLuaApi::Button20Click(TObject *Sender)
{
	int i,k, m, n;
    AnsiString s;
	char aBuf[94*2];
    char tempbuf[94 * 2];

	if (CheckBoxClear->Checked)
	{
		Memo1->Lines->Clear();
	}

//	Memo1->Lines->Add("\
//    区位码是国家标准信息交换用汉字编码GB2312-80中汉字的区位编码。\
//根据其位置分为94区，每个区94个字符，区的编码是从1~94,\
//位的编码从1~64。区位码的第1个字节是区码,第2字节是位码。\
//将汉字机内码中的两个ASCII字符各减去160就是区位码。\
//第16区第1位对应汉字(啊)，之前的是各类数字字母符号(全角)。\r\n\
//	国标一级字库最大区号为55, 汉字个数为: (55-16+1)x94 = 3760\r\n\
//    国标一二级字库最大区号为87, 汉字个数为: (87-16+1)x94 = 6768\
//");


    for(i=0;i<128;i++){
        if(i<' '){
            aBuf[i]=' ';
        }
		else{
            aBuf[i]=i;
        }
    }
    aBuf[128]=0;
  //  s.sprintf(aBuf);
  //  FormView->Image1->Canvas->TextOutA(0,0,s);

	Memo1->Lines->Add("");
	Memo1->Lines->Add("【ASCII区】");
    m = 0;
    for(i=1;i<128;i++)
    {
        tempbuf[m++] = i;
    }
	tempbuf[m++] = 0;
	Memo1->Lines->Add((AnsiString)tempbuf);

	Memo1->Lines->Add("");
	Memo1->Lines->Add("【全角字符区】");
    for(i=0;i<9;i++){
        m = 0;
        for(k=0;k<94;k++){
            aBuf[2*k]=i+1+160;
            aBuf[2*k+1]=k+1+160;

            tempbuf[m++] = i+1+160;
            tempbuf[m++] = k+1+160;
        }
        tempbuf[m++] = 0;

		Memo1->Lines->Add((AnsiString)tempbuf);
       //s.sprintf(aBuf);
        //FormView->Image1->Canvas->TextOutA(0,(i+1)*12,s);
    }

//	Memo1->Lines->Add("");
//	Memo1->Lines->Add("【汉字区】");
//    for(i=16;i<88;i++){
//    	m = 0;
//        for(k=0;k<94;k++){
//            aBuf[2*k]=i+160;
//            aBuf[2*k+1]=k+1+160;
//
//            tempbuf[m++] = i+160;
//            tempbuf[m++] = k+1+160;
//        }
//        tempbuf[m++] = 0;
//
//        Memo1->Lines->Add((AnsiString)tempbuf);
//        //s.sprintf(aBuf);
//        //FormView->Image1->Canvas->TextOutA(0,(i-6)*12,s);
//	}
}
//---------------------------------------------------------------------------


