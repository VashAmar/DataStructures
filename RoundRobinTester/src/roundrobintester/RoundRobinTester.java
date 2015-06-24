/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//main method used to impliment the round robin algorithm
package roundrobintester;

/**
 *
 * @author Vashista
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RoundRobinTester {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Process command line arguments
        // read the file
        
        
        Scanner sc = new Scanner(System.in);
        Scanner sc1 = new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);
        Scanner quantinput = new Scanner(System.in);
        int quantum =0;
        System.out.println("Enter a Quantum Time:");
        quantum = quantinput.nextInt();
        
                
        
        String filename ;
        String allocationStrategy;
        
        
        filename = "testing.txt";
        allocationStrategy = "FCFS";
        
        
        
        
        if(args.length==3){
            quantum = new Integer(args[2]);
        }
        
        BufferedReader br = null;
        
        try {
            
            String sCurrentLine;
            
            br = new BufferedReader(new FileReader("C://Users/Vashista/Desktop/"+filename));
           
            
            List<Job> jobList = new ArrayList<Job>();
            while ((sCurrentLine = br.readLine()) != null) {
                
                String a[] = sCurrentLine.split(",");
                int processId = new Integer(a[0]);
                int arrivalTime = new Integer(a[1]);
                int cpuTime = new Integer(a[2]);
                
                Job job = new Job(processId,arrivalTime,cpuTime);
                
                jobList.add(job);
                
                
            }
           
            
                RoundRobin roundRobin = new RoundRobin();
                roundRobin.run(jobList,quantum);
                
            
            
            } catch (IOException e) {
            e.printStackTrace();
            } finally {
            try {
                if (br != null)br.close();
                } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
        
        JobFinishEvent callback = new JobFinishEvent() {
            @Override
            public void onFinish(Job j) {
                // this will be called when a job is finished.
            }
        };
        
        

    }
    
}
