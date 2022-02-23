import java.awt.*;
import java.io.IOException;

public class PlotSomeData
{
    public static void main(String[] args) throws IOException
    {
        // Question 4
        // Initialize array to all 0's
        int maxIterations[] = new int[101];
        for(int i = 0; i < maxIterations.length; i++){
            maxIterations[i] = 0;
        }
        // Loop through possible values of m and n
        for(int m = 1; m <= 100; m++){
            for(int n = 1; n <= m; n++){
                maxIterations[n] = Lab1.max(maxIterations[n], Lab1.gcdIterations(m, n));
            }
        }
        // You can modify this to plot your gcdIterations data - sdg
        Plot.Data curve1 = Plot.data();
        Plot.Data curve2 = Plot.data();
        Plot.Data curve3 = Plot.data();

        for (int x=1; x<101; x++)
        {
            curve1.xy(x, maxIterations[x]); // y = maxIterations[x]
            curve2.xy(x, 2*(Math.ceil(Math.log10(x) / Math.log10(2)))); // y = 2ceil(logx) (base 2)
            curve3.xy(x, 2*Math.log(x)); // 2 * ln(x)
        }

        Plot plot = Plot.plot(Plot.plotOpts().
                title("Lab 1 Question 4").
                legend(Plot.LegendFormat.BOTTOM)).
                    xAxis("x", Plot.axisOpts().range(1, 100)).
                    yAxis("y", Plot.axisOpts().range(0, 15)).

                series("y=maxIterations[x]", curve1, Plot.seriesOpts().color(Color.BLACK)).
                series("y=2*ceil(logx)", curve2, Plot.seriesOpts().color(Color.BLUE)).
                series("y=2*ln(x)", curve3, Plot.seriesOpts().color(Color.RED));

        plot.save("plot", "png");
    }
}