import java.sql.*;

public class jdbc1
{       static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
        static final String DB_URL = "jdbc:mysql://localhost/DB1";
        static final String USER = "root";
        static final String PASS = "rooter"; 

        public static void main(String[] args)
        {       Connection conn = null;
                Statement stmt = null;
        
                try
                {       //register jdbc driver
                        System.out.println("jdbcDriver");
                    //    Class.forName("com.mysql.jdbc.Driver.jar");
                        
                        System.out.println("connection");
                        //open connection
                        conn = DriverManager.getConnection(DB_URL,USER,PASS);
                        // execute querry
                        stmt = conn.createStatement();
                        String sqlQuerry;
                        sqlQuerry = "SELECT * from TABLE1";
                        ResultSet rs = stmt.executeQuery(sqlQuerry);
                        
                        //retrieve by Coloumn name
                        while(rs.next())
                        {       int id = rs.getInt("id");
                                int age = rs.getInt("age");
                                String name = rs.getString("name");
                                
                                // display values
                                System.out.print("ID: "+id);
                                System.out.print(", age: "+age);
                                System.out.println(",name: "+name);
                        };
                        
                        //cleanup enviornment
                        rs.close();
                        stmt.close();
                        conn.close();
                }
                catch(SQLException se)
                {       se.printStackTrace();
                }
                catch(Exception e)
                {       e.printStackTrace();
                }
        }
}

