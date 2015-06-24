package roundrobintester;


import roundrobintester.Job;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Vashista
 */
//interface that is implemented to finish the job
public interface JobFinishEvent {
    public void onFinish(Job j);
    
}
