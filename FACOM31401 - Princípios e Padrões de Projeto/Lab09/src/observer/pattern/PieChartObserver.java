package observer.pattern;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.Vector;

import javax.swing.JPanel;

import observer.CourseRecord;
import observer.LayoutConstants;

/**
 * This class represents a bar chart view of a vector of data. Uses the Observer
 * pattern.
 */
@SuppressWarnings("serial")
public class PieChartObserver extends JPanel implements Observer {
    private Vector<CourseRecord> courseData;
    /**
     * Creates a BarChartObserver object
     *
     * @param data
     *            a CourseData object to observe
     */
    public PieChartObserver(CourseData data) {
        data.attach(this);
        this.courseData = data.getUpdate();

        int radius = 100;

        this.setPreferredSize(new Dimension(
                2 * LayoutConstants.xOffset + 2 * radius,
                2 * LayoutConstants.yOffset + 2 * radius + 300 // aumenta margem para a legenda
        ));


        this.setBackground(Color.white);
    }

    /**
     * Paint method
     *
     * @param g
     *            a Graphics object on which to paint
     */
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        if (courseData == null || courseData.size() == 0)
            return;

        int radius = 100;

        Integer[] data = new Integer[courseData.size()];
        String[] labels = new String[courseData.size()];
        for (int i = 0; i < courseData.size(); i++) {
            CourseRecord rec = courseData.get(i);
            data[i] = rec.getNumOfStudents();
            labels[i] = rec.getName();
        }

        double total = 0.0;
        for (int num : data) {
            total += num;
        }

        if (total > 0) {
            double startAngle = 0.0;
            for (int i = 0; i < data.length; i++) {
                double ratio = (data[i] / total) * 360.0;
                g.setColor(LayoutConstants.subjectColours[i % LayoutConstants.subjectColours.length]);
                g.fillArc(LayoutConstants.xOffset, LayoutConstants.yOffset + 50,
                        2 * radius, 2 * radius,
                        (int) startAngle, (int) ratio);
                startAngle += ratio;
            }
        }

        int legendX = LayoutConstants.xOffset;
        int legendY = LayoutConstants.yOffset + 2 * radius + 70;
        int boxSize = 15;
        int spacing = 25;

        g.setColor(Color.black);
        g.drawString("Legenda:", legendX, legendY - 10);

        for (int i = 0; i < labels.length; i++) {
            g.setColor(LayoutConstants.subjectColours[i % LayoutConstants.subjectColours.length]);
            g.fillRect(legendX, legendY + i * spacing, boxSize, boxSize);

            g.setColor(Color.black);
            g.drawRect(legendX, legendY + i * spacing, boxSize, boxSize);
            g.drawString(labels[i], legendX + boxSize + 5, legendY + i * spacing + boxSize - 3);
        }
    }

    /**
     * Informs this observer that the observed CourseData object has changed
     *
     * @param o
     *            the observed CourseData object that has changed
     */
    @Override
    public void update(Observable o) {
        CourseData data = (CourseData) o;
        this.courseData = data.getUpdate();

        this.repaint();
    }
}
