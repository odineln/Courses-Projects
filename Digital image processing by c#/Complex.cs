using System;

public class Complex
{

     //复数的实部
        private double real = 0.0;
    //复数的虚部
    private double imaginary = 0.0;
    //实部的属性
    public double Real
    {
        get
        {
            return real;
        }
        set
        {
            real = value;
        }
    }
    //虚部的属性
    public double Imaginary
    {
        get
        {
            return imaginary;
        }
        set
        {
            imaginary = value;
        }
    }
    //基本构造函数
    public Complex()
    {
    }
    //指定值得构造函数
    public Complex(double dbreal, double dbimag)
    {
        real = dbreal;
        imaginary = dbimag;
    }
    //复制构造函数
    public Complex(Complex other)
    {
        real = other.real;
        imaginary = other.imaginary;
    }
    //重载+运算符
    public static Complex operator +(Complex comp1, Complex comp2)
    {
        return comp1.Add(comp2);
    }
    //重载-运算符
    public static Complex operator -(Complex compl, Complex comp2)
    {
        return compl.Subtract(comp2);
    }
    //重载*运算符
    public static Complex operator *(Complex compl, Complex comp2)
    {
        return compl.Multiply(comp2);
    }
    //实现复数加法
    public Complex Add(Complex comp)
    {
        double x = real + comp.real;
        double y = imaginary + comp.imaginary;
        return new Complex(x, y);
    }
    //实现复数减法
    public Complex Subtract(Complex comp)
    {
        double x = real - comp.real;
        double y = imaginary - comp.imaginary;
        return new Complex(x, y);
    }
    //实现复数乘法
    public Complex Multiply(Complex comp)
    {
        double x = real * comp.real - imaginary * comp.imaginary;
        double y = real * comp.imaginary + imaginary * comp.real;
        return new Complex(x, y);
    }
    //求幅度
    public double Abs()
    {
        //取得实部的绝对值
        double x = Math.Abs(real);
        //取得虚部的绝对值
        double y = Math.Abs(imaginary);
        //实部为0
        if (real == 0)
        {
            return y;
        }
        //虚部为0
        if (imaginary == 0)
        {
            return x;
        }
        //计算模
        if (x > y)
        {
            return (x * Math.Sqrt(1 + (y / x) * (y / x)));
        }
        else
        {
            return (y * Math.Sqrt(1 + (y / x) * (y / x)));
        }
    }
    //求相位角
    public double Angle()
    {
        //实数和虚数都为0
        if (real == 0 && imaginary == 0)
            return 0;
        if (real == 0)
        {
            //实部位0
            if (imaginary > 0)
                return Math.PI / 2;
            else
                return -Math.PI / 2;
        }
        else
        {
            if (real > 0)
            {
                //实部大于0
                return Math.Atan2(imaginary, real);
            }
            else
            {
                //实部小于0
                if (imaginary >= 0)
                    return Math.Atan2(imaginary, real) + Math.PI;
                else
                    return Math.Atan2(imaginary, real) - Math.PI;
            }
        }
    }
    //共轭复数
    public Complex conjugate()
    {
        return new Complex(this.real, -this.imaginary);
    }

	
}
