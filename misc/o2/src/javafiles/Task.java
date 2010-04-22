import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;



/**
 * Representation of a task/activity in a project.
 * 
 * @author (your name) 
 */
public class Task
{
    // feel free to change the fields as necessary
    
    /** Unique task name */
    private String name;
    
    /** The time it takes to complete the task */
    private int duration;
    
    /** List of tasks which must be completed
     * this task can start     */
    private List<Task> predecessors;
    
    /** Earliest time this task can start */
    private int earliestStart;
    
    /** Latest time this task can start */
    private int latestStart;
    

    /** This constructor is used by the project
     * file loader (Project.load())   */
    public Task(String name) {
        // init task object
    }
    
    
    /** Set task duration - used by file loader */
    public void setDuration(int duration) {
    }
    
    
    /** Add a task which must be finished before
     * this can start - used by file loader   */
    public void addPredecessor(Task t) {
    }
    
    
    // add methods as necessary
}
