import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


/**
 * Write a description of class Project here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Project
{
    /** List of tasks */
    private Map<String,Task> tasks;
    
    
    /** Create project from data file
     *  @param filename     */
    public Project(String filename) throws IOException {
        tasks = new HashMap<String,Task>();
        load(filename);
    }
    
    
    /** Get a task by name.
     * Create the task if necessary.
     * @param name task name     */
    private Task getTask(String name) {
        Task t = tasks.get(name);
        if (null == t) {
            t = new Task(name);
            tasks.put(name, t);
        }
        return t;
    }
    
    
    /** Load project from file
     * @param filename      */
    private void load(String filename) throws IOException {
        FileReader fr = new FileReader(filename);
        load(new BufferedReader(fr));
        fr.close();
    }
    
    
    
    /** Load project from open file */
    private void load(BufferedReader in) throws IOException {
        for (String line = in.readLine();
             line != null;
             line = in.readLine()) {
            // skip blank lines and comments
            line = line.trim();
            if (line.equals("") || line.startsWith("#")) {
                // do nothing
            }
            else { // parse task definition
                // taskname duration: dep1 dep2 dep3 ...    
                Scanner s = new Scanner(line);
                String name = s.next();
                int duration = s.nextInt();
                // skip the colon ':'
                s.next();
                Task task = getTask(name);
                task.setDuration(duration);
                
                // get dependencies
                while (s.hasNext()) {
                    String depname = s.next();
                    Task dep = getTask(depname);
                    task.addPredecessor(dep);
                }
            }
        }
        save(System.out);
    }
    
    
    // debug print
    private void save(PrintStream out) {
        out.println();
        for (Task t : tasks.values()) {
            // print task information
            // t.save(out);
        }
    }
    
    
    // test it
    public static void main(String[] args) throws IOException {
        Project p = new Project("testproject.txt");
        
        // call method that solves the problem
    }
}
