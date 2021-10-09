import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.DriverManager;

public class JDBCexample {
    public static void main(String[] args){
        try { 
            Class.forName ("com.mysql.jdbc.Driver"); 
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/bnam", "bnam", "changethis"); 
            Statement stmt = conn.createStatement(); 

            ResultSet rset = stmt.executeQuery(
                    "select ID, name, dept_name, salary " + 
                    "from instructor " + 
                    "where name = '" + args[0] + "'" );

            while (rset.next()) {
                System.out.printf("%10s %10s %12s %10.2f\n", 
                           rset.getString("ID"),                                 
                           rset.getString("name"),                                 
                           rset.getString("dept_name"),                                 
                           rset.getFloat(4));     
            }

            stmt.close();    
            conn.close();    
        }        
        catch (SQLException sqle) {         
            System.out.println("SQLException : " + sqle);        
        }
        catch (Exception e) {         
            System.out.println("Exception : " + e);        
        }
    }
}
