package roundrobintester;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vashista
 * 
 */

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Queue;

public abstract class AllocationStrategy {
    protected List<Job> Jobs;
    protected ArrayList<Job> Queue;
    
    public AllocationStrategy(List<Job> jobs) {
        super();
        Jobs = jobs;
    }
    
    public abstract void run();
    // update current job by 1 tick
    // check if the job queue might need to be changed.
    // check for jobs to add to the queue
    
}
