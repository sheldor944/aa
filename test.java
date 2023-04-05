class A {
    static int i ; 
    A()
    {
        i++ ; 
        System.out.println("in A i is " + i );
    }
    static void aja()
    {
        System.out.println("Hello bangladesh ");
    }
    static{
        System.out.println("call to hobei hobe ");
    }
    // int get()
    // {
    //     System.out.println("returned from A ");
    //     return i ; 
    // }
}

class B extends A {
    B(){
        i++ ; 
        System.out.println("in B i is " + i );
    }

    int get()
    {
        System.out.println("returned from B ");
        return i ; 
    }
}

class C extends B {
    C()
    {
        i++ ; 
        System.out.println("in c i is " + i);
    }
    int get()
    {
        System.out.println("returned from C ");
        return i ; 
    }
}

class D extends C {
    D()
    {
        i++ ; 
        System.out.println("in D i is " + i );
    }
    void f()
    {
        System.out.println("hello ");
    }
}


public class test extends D {
    public static void main(String arrgs[])
    {
        // test obj_test = new test() ; 
        // System.out.println();
        // D obj_D = new D() ;  
        // System.out.println(obj_D.get());
        // B objB= new B(); 
        // C objC = new C() ; 
        // objB = (B) obj_D ; 

        // System.out.println(objB instanceof C);
        aja();
        System.out.println(i );
        A a = new A()  ; 
        // System.out.println(obj_D.get());

    }
}