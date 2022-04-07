void report_weekly_monthly(int day)
{
    if (day%7 == 0)
    {
        int sort_selection;
        // First of all, we ask the controller to choose which kind of sort for the report
        // he wants.

        cout<<"It is the time for making weekly report, Please choose the mode"<<endl;
        cout<<"1 : not sort at all"<<endl;
        cout<<"2 : sort by profession category"<<endl;
        cout<<"3 : sort by age group"<<endl;
        cout<<"4 : sort by name"<<endl;

        cin>>sort_selection;
        switch (sort_selection)
        {
        case 1:
            print_original();
            break;
        case 2:
            print_proffession_sorted();
            break;
        case 3:
            print_age_sorted();
            break;
        case 4:
            print_name_sorted();
            break;
        default: cout<<"Wrong input! Please restart the program and choose what you want again!"
            break;
        }

        void print_original()
        {
            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }

            }

            cout<<"The list that people have registered"<<enl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }

            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }

        void print_proffession_sorted()
        {

            //用斐波那契堆排序

            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }
            }

            cout<<"The list that people have registered"<<enl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }

            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }
            
            
        }
        void print_age_sorted()
        {

            //用斐波那契堆排序

            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }
            }

            cout<<"The list that people have registered"<<enl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }

            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }

        }

        void print_name_sorted()
        {

            //用姓名排序
            
            cout<<"The list that people have been treated"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是以被治疗")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册到治疗之间花的时间"<<endl;
                }
            }

            cout<<"The list that people have registered"<<enl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是已注册的")
                {
                    cout<<"这个节点的职业，年龄，风险以及从注册至今共多少时间"<<endl;
                }   
            }

            cout<<"The list that people is queueing"<<endl;
            while ("这个节点的next不是null的时候")
            {
                if("他的状态是排队中的")
                {
                    cout<<"这个节点的职业，年龄，风险以及排队排了多久了"<<endl;
                }
            }
            
        }

        
            
        }


    }
}
node* pop_sorted()
{
    
}
