/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package vaanimatedsort;

import java.util.Random;

/**
   This class contains utility methods for array manipulation.
*/  
public class VAArray
{ 
   private static Random generator = new Random();

   /**
      Creates an array filled with random values.
      @param length the length of the array
      @param n the number of possible random values
      @return an array filled with length numbers between
      0 and n - 1
   */
   public static int[] VArandomArray(int length, int n)
   {  
      int[] ar = new int[length];      
      for (int i = 0; i < ar.length; i++)
      {
         ar[i] = generator.nextInt(n);
      }
      
      return ar;
   }

   /**
      Swaps two entries of an array.
      @param a the array
      @param i the first position to swap
      @param j the second position to swap
   */
   public static void swap(int[] a, int i, int j)
   {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
   }
}
