/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package vaanimatedsort;
import java.awt.*;
import javax.swing.*;


/**
   A component that displays the current state of the selection sort algorithm.
*/
public class VASelectionSortComponent extends JComponent
{
   private VASelectionSorter sorter;

   /**
      Constructs the component.
   */
   public VASelectionSortComponent()
   {
      int[] values = VAArray.VArandomArray(30, 400);
      sorter = new VASelectionSorter(values, this);
   }

   public void paintComponent(Graphics g)
   {
      sorter.draw(g);
   }

   /**
      Starts a new animation thread.
   */
   public void startAnimation()
   {
      class AnimationRunnable implements Runnable
      {
         public void run()
         {
            try
            {
               sorter.sort();
            }
            catch (InterruptedException exception)
            {
            }
         }
      }
      
      Runnable r = new AnimationRunnable();
      Thread t = new Thread(r);
      t.start();
   }
   
}
