/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package vaanimatedsort;

import java.awt.*;
import javax.swing.*;

/**
 *
 * @author Vashista Amarjit
 */
public class VAAnimatedSort {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
   {
      JFrame frame = new JFrame("Vashista Animated Selection Sort");

      final int FRAME_WIDTH = 400;
      final int FRAME_HEIGHT = 500;

      frame.setSize(FRAME_WIDTH, FRAME_HEIGHT);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      final VASelectionSortComponent component 
            = new VASelectionSortComponent();
      frame.add(component, BorderLayout.CENTER);

      frame.setVisible(true);
      //center frame on screen
      Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
      frame.setLocation(dim.width/2-frame.getSize().width/2, dim.height/2-frame.getSize().height/2);
      //start animation
      component.startAnimation();
   }
    
}