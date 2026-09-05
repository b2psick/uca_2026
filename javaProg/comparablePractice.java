import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    static class UCAStudent implements Comparable<UCAStudent> {
        String studentName;
        double CGPA;
        
        UCAStudent(String studentName, double CGPA) {
            this.studentName = studentName;
            this.CGPA = CGPA;
        }
        
        public int compareTo(UCAStudent e2) {
            UCAStudent e1 = this;
            
           // e1 on top then return negative value
           // e2 on top then return postive value
           // if equal return zero value
           return Double.compare(e2.CGPA , e1.CGPA);
        }
        
        public String toString() {
            return studentName + " " + CGPA;
        }
    }
    
    public static void main (String[] args) throws java.lang.Exception
    {
        List<UCAStudent> list  = new ArrayList<>();
        list.add(new UCAStudent("A", 6.0d));
        list.add(new UCAStudent("B", 7.0d));
        list.add(new UCAStudent("C", 8.0d));
        
        Collections.sort(list);
        
        System.out.println(list);
    }
}