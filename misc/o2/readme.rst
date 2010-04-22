    1, A project can be represented as a graph, where the nodes represents tasks that have to be carried out. We can interpret an edge from task B to task A as a dependency, and as a simplification we will assume that it means that task A must be finished before task B can start. To simplify matters further we assume that there is a 'Start' task which all other tasks depend on, and an 'End' task which depends on all other tasks. 
    (It would also be possible to let the nodes represent states, or milestones, and the edges represent the tasks that must be done to reach the milestone.)

    2, Given the simplification in 1, some interesting properties of the project can be computed from the graph:

    Earliest start of each task:
    -----------------------------
    
    The earliest possible start of a task is when all its predecessors are finished. In the graph this is the length of the longest path from the task to the 'Start' task.
    The duration of the project is the earliest start of the 'End' task, which is the length of the longest path from the 'End' node to the 'Start' node.

    Latest start of each task:
    ---------------------------
    
    When we have found the earliest start of each task, and the duration of the project, we can find the latest time a task can start without delaying the project:
    We work from the 'End' task, where the latest start must be the same as the earliest start (otherwise the project would be delayed)
    Any other task must end before the latest start of all task that depends on it. That is its latest start is the minimum of the latest start of the successors, minus its own duration.

    Slack and critical path
    -------------------------
    
    The difference between the earliest possible start and the latest possible start is called slack. It is the amount of time the task can be delayed without delaying the project.
    Tasks with zero slack cannot be delayed without delaying the project. They are critical to completing the project on time.
    A critical path is any path from 'End' to 'Start' where all tasks have zero slack.
    
    3, Download the "Project" project from ClassFronter and use it as the basis for a program which will find the earliest and latest start times for all tasks in a project, and the critical paths for the project.